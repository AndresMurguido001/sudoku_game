#include "board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace ftxui;

void Board::set(int i, int j, int val) { board[i][j] = val; }

int Board::get(int i, int j) { return board[i][j]; }
Board::Board(std::vector<std::vector<int>> vals)
    : board(vals){};

void Board::print() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      std::cout << board[i][j];
    }
    std::cout << "\n";
  }
}

Board::~Board() {}
