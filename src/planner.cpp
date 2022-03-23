#include <iostream>
#include <vector>
#include <algorithm>

#include "planner.h"
#include "cell.h"

Planner::Planner(int width, int height, int x, int y)
{
  grid_width = width;
  grid_height = height;
  dest_x = x;
  dest_y = y;
}

// set the destination position. This is used when the destination is changed.
void Planner::SetDestination(int x, int y)
{
  dest_x = x;
  dest_y = y;
}

// add neigbor cells to the neigbors vector
void Planner::AddNeighbors(Snake *snake)
{
  neighbors.clear();
  int x = static_cast<int>(snake->head_x);
  int y = static_cast<int>(snake->head_y);
  // left
  if (x - 1 >= 0 && (snake->size == 1 || snake->direction != Snake::Direction::kRight))
  {
    std::unique_ptr<Cell> c = std::make_unique<Cell>(x - 1, y, Snake::Direction::kLeft, dest_x, dest_y);
    neighbors.push_back(std::move(c));
  }
  // right
  if (x + 1 < grid_width && (snake->size == 1 || snake->direction != Snake::Direction::kLeft))
  {
    std::unique_ptr<Cell> c = std::make_unique<Cell>(x + 1, y, Snake::Direction::kRight, dest_x, dest_y);
    neighbors.push_back(std::move(c));
  }
  // up
  if (y - 1 >= 0 && (snake->size == 1 || snake->direction != Snake::Direction::kDown))
  {
    std::unique_ptr<Cell> c = std::make_unique<Cell>(x, y - 1, Snake::Direction::kUp, dest_x, dest_y);
    neighbors.push_back(std::move(c));
  }
  // down
  if (y + 1 < grid_height && (snake->size == 1 || snake->direction != Snake::Direction::kUp))
  {
    std::unique_ptr<Cell> c = std::make_unique<Cell>(x, y + 1, Snake::Direction::kDown, dest_x, dest_y);
    neighbors.push_back(std::move(c));
  }
}

// sorting function
bool Compare(const std::unique_ptr<Cell>& c1, const std::unique_ptr<Cell>& c2) {
  return c1->distance > c2->distance;
}

// find the closest cell and return it
Cell *Planner::NextCell()
{
  sort(this->neighbors.begin(), this->neighbors.end(), Compare);
  return this->neighbors[this->neighbors.size()-1].get();
}
