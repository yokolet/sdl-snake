#ifndef CELL_H
#define CELL_H

#include <limits>
#include <vector>
#include <cmath>
#include "snake.h"

class Cell
{
public:
  int x = 0;
  int y = 0;
  float distance = 0.0;
  Snake::Direction direction = Snake::Direction::kUp; // up, down, left or right of the snake head
  Cell() {}
  Cell(int pos_x, int pos_y, Snake::Direction d) : x(pos_x), y(pos_y), direction(d) {}
  void UpdateDistance(Cell other);
private:
};

#endif
