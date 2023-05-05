#include "board.h"
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/node.hpp"
#include <algorithm>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/canvas.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace ftxui;

void Board::set(int i, int j, int val) { this->board[i][j] = val; }

int Board::get(int i, int j) { return this->board[i][j]; }
Board::Board()
    : board(std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE>{0}){};

Board::~Board() {}
