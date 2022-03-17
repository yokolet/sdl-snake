#include <iostream>
#include <vector>

#include "planner.h"
#include "cell.h"

Planner::Planner(int width, int height, int x, int y)
{
  grid_width = width;
  grid_height = height;
  dest_x = x;
  dest_y = y;
}

void Planner::SetDestination(int x, int y)
{
  dest_x = x;
  dest_y = y;
}

void Planner::AddNeighbors(Snake *snake)
{
  neighbors.clear();
  int x = static_cast<int>(snake->head_x);
  int y = static_cast<int>(snake->head_y);
  // left
  if (x - 1 >= 0)
  {
    Cell c = Cell(x - 1, y, Snake::Direction::kLeft, dest_x, dest_y);
    neighbors.push_back(c);
  }
  // right
  if (x + 1 < grid_width)
  {
    Cell c = Cell(x + 1, y, Snake::Direction::kRight, dest_x, dest_y);
    neighbors.push_back(c);
  }
  // up
  if (y - 1 >= 0)
  {
    Cell c = Cell(x, y - 1, Snake::Direction::kUp, dest_x, dest_y);
    neighbors.push_back(c);
  }
  // down
  if (y + 1 < grid_height)
  {
    Cell c = Cell(x, y + 1, Snake::Direction::kDown, dest_x, dest_y);
    neighbors.push_back(c);
  }
}

bool Compare(Cell c1, Cell c2) {
  return c1.distance > c2.distance;
}

Cell Planner::NextCell()
{
  sort(this->neighbors.begin(), this->neighbors.end(), Compare);
  auto c = this->neighbors.back();
  return c;
}
