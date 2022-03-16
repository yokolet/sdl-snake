#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include "cell.h"
#include "snake.h"

class Planner
{
public:
  Planner(int width, int height, int x, int y);
  void AddNeighbors(Snake *snake);
  void UpdateDistances();
  Cell *NextCell();
private:
  std::vector<Cell *> neighbors;
  int grid_width;
  int grid_height;
  Cell destination = Cell();
};

#endif
