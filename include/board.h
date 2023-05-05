#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>

const int BOARD_SIZE = 9;

struct Cell {};

// Board should contain cells and state of game;
class Board {
public:
  Board();
  ~Board();
  std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> board;
  int get(int, int);
  void set(int, int, int);
  void print();
  void update_color(int, int);

private:
  void make_grid(int, int);
};

#endif
