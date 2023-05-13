#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <vector>

const int BOARD_SIZE = 9;

struct Cell {};

// Board should contain cells and state of game;
class Board {
public:
  Board(std::vector<std::vector<int>> vals);
  ~Board();
  std::vector<std::vector<int>> board;
  int get(int, int);
  void set(int, int, int);
  void print();
  void update_color(int, int);

private:
  void make_grid(int, int);
};

#endif
