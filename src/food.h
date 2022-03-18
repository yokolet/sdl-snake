#ifndef FOOD_H
#define FOOD_H

class Food
{
public:
  int x;
  int y;
  bool safe;
  Food() : x(0), y(0), safe(true) {}
  Food(int x, int y, bool safe) : x(x), y(y), safe(safe) {}
  ~Food() {}
private:
};

#endif
