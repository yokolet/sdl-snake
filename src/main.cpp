#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::vector<int> scores = game.GetScores();
  std::vector<int> sizes = game.GetSizes();
  std::cout << "Score: snake: " << scores[0] << ", autonomous: " << scores[1] << "\n";
  std::cout << "Size: snake: " << sizes[0] << ", autonomous: " << sizes[1] << "\n";
  return 0;
}