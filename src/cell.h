#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include "snake.h"

class Cell
{
public:
  Cell() {}
  Cell(int pos_x, int pos_y, Snake::Direction d, int dest_x, int dest_y);
  ~Cell();
  int x = 0;
  int y = 0;
  float distance = 0.0;
  Snake::Direction direction = Snake::Direction::kUp; // up, down, left or right of the snake head
private:
};

#endif
