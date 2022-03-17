#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "planner.h"

class Controller
{
public:
  void HandleInput(bool &running, Snake &snake) const;
  void HandleSearch(bool &running, Snake &snake, Planner &planner) const;

private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
