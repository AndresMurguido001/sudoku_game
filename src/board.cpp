#include "board.h"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/node.hpp"
#include <algorithm>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/canvas.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ftxui/dom/elements.hpp"

using namespace ftxui;

// Try making a grid of buttons for the sudoku board

void Board::set(int i, int j, int val) {
    board[i][j] = val;
}


// Use canvas. Move rendering logic to main()
Board::Board():
    board(std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE>{0}){};

Board::~Board(){}
