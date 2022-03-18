#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void RenderFood(SDL_Renderer *sdl_renderer, std::unique_ptr<Food> const &f, SDL_Rect &b)
{
  if (f->safe)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  }
  else
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x7D, 0x3C, 0x98, 0xFF);
  }

  b.x = f->x * b.w;
  b.y = f->y * b.h;
  SDL_RenderFillRect(sdl_renderer, &b);
}

void RenderSnake(SDL_Renderer *sdl_renderer, Snake const &s, SDL_Rect &b)
{
  // Render snake's body
  if (s.manual)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  }
  else
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xAA, 0xAA, 0xAA, 0xAA);
  }

  for (SDL_Point const &point : s.body)
  {
    b.x = point.x * b.w;
    b.y = point.y * b.h;
    SDL_RenderFillRect(sdl_renderer, &b);
  }

  // Render snake's head
  b.x = static_cast<int>(s.head_x) * b.w;
  b.y = static_cast<int>(s.head_y) * b.h;
  if (s.alive && s.manual)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  }
  else if (s.alive && !s.manual)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0xBB, 0x7A);
  }
  else
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &b);
}

void Renderer::Render(Snake const snake, Snake automonous, std::unique_ptr<Food> const &food)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  RenderFood(sdl_renderer, food, block);

  // Render snakes
  RenderSnake(sdl_renderer, snake, block);
  RenderSnake(sdl_renderer, automonous, block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(std::vector<int> scores, int fps)
{
  std::string title{"Snake Score: " + std::to_string(scores[0]) + " vs " + std::to_string(scores[1]) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
