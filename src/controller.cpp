#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const
{
  if (snake.direction != opposite || snake.size == 1)
    snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        ChangeDirection(snake, Snake::Direction::kUp,
                        Snake::Direction::kDown);
        break;

      case SDLK_DOWN:
        ChangeDirection(snake, Snake::Direction::kDown,
                        Snake::Direction::kUp);
        break;

      case SDLK_LEFT:
        ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
        break;

      case SDLK_RIGHT:
        ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
        break;
      }
    }
  }
}

const char* ToString(Snake::Direction v)
  {
      switch (v)
      {
          case Snake::Direction::kUp:   return "Up";
          case Snake::Direction::kDown:   return "Down";
          case Snake::Direction::kLeft: return "Left";
          case Snake::Direction::kRight: return "Right";
          default:      return "[Unknown Direction]";
      }
  }

void Controller::HandleSearch(bool &running, Snake &snake, Planner &planner) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else
    {
      planner.AddNeighbors(&snake);
      Cell c = planner.NextCell();
      //std::cout << "next cell x: " << c.x << ", y: " << c.y << ", dist: " << c.distance << ", direction: " <<  ToString(c.direction) << std::endl;
      snake.direction = c.direction;
      break;
    }
  }
}
