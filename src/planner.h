#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include "cell.h"
#include "snake.h"

class Planner
{
public:
  Planner() {}
  Planner(int width, int height, int x, int y);
  void SetDestination(int x, int y);
  void AddNeighbors(Snake *snake);
  void UpdateDistances();
  Cell NextCell();
private:
  std::vector<Cell> neighbors;
  int grid_width;
  int grid_height;
  int dest_x;
  int dest_y;
};

#endif
