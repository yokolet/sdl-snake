#ifndef FOOD_H
#define FOOD_H

class Food
{
public:
  int x;
  int y;
  bool safe; // this food is safe (true) or unsafe (false)
  Food() : x(0), y(0), safe(true) {}
  Food(int x, int y, bool safe) : x(x), y(y), safe(safe) {}
  ~Food() {}
private:
};

#endif
