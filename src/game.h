#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "planner.h"
#include "food.h"

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  std::vector<int> GetScores() const;
  std::vector<int> GetSizes() const;

private:
  Snake snake;
  Snake autonomous;
  //SDL_Point food;
  std::unique_ptr<Food> food;
  Planner planner;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void PlaceFood();
  void Update(Snake& s);
};

#endif