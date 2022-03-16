#include "cell.h"

void Cell::UpdateDistance(Cell other)
{
  distance = std::abs(x - other.x) + std::abs(y - other.y);
}
