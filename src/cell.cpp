#include "cell.h"

Cell::Cell(int pos_x, int pos_y, Snake::Direction d, int dest_x, int dest_y)
{
  x = pos_x;
  y = pos_y;
  direction = d;
  distance = std::abs(x - dest_x) + std::abs(y - dest_y);
}
