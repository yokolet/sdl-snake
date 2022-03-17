#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include <memory>
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
  Cell* NextCell();
private:
  std::vector<std::unique_ptr<Cell>> neighbors;
  int grid_width;
  int grid_height;
  int dest_x;
  int dest_y;
};

#endif
