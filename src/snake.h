#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake
{
public:
  enum class Direction
  {
    kUp,
    kDown,
    kLeft,
    kRight
  };

  Snake(int grid_width, int grid_height, bool manual)
      : grid_width(grid_width),
        grid_height(grid_height),
        manual(manual),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  Snake(int grid_width, int grid_height)
      : Snake(grid_width, grid_height, true) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  int score{0};
  bool alive{true};
  bool manual{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
