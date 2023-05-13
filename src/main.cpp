#include "board.h"
#include "ftxui/component/screen_interactive.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <memory>
#include <pthread.h>
#include <string>
#include <utility>
#include <vector>
using namespace ftxui;

int main(int argc, char *argv[]) {
  // Render board
  int mouse_x = 0, mouse_y = 0;
  int col_sync = 0;
  Component board_component;

  // Trying new board design;
  Components inner_board;
  std::vector<std::vector<int>> test_board(BOARD_SIZE,
                                           std::vector<int>(BOARD_SIZE, 0));

  Board game_board(std::move(test_board));

  for (int i = 0; i < BOARD_SIZE; i++) {

    Components rows = {};

    for (int j = 0; j < BOARD_SIZE; j++) {

      int *cell_val = &game_board.board[i].at(j);
      rows.push_back(
          Renderer([&, cell_val](bool focus) {
            auto text = ftxui::text(std::to_string(*cell_val));
            if (focus)
              text |= bgcolor(Color::DarkMagenta);
            return text;
          }) |
          CatchEvent([&, i, j](Event e) {
            if (!(e.character().at(0) <= '9' && e.character().at(0) > '0'))
              return false;

            int n = std::stoi(e.character());
            game_board.set(i, j, n);

            return true;
          }));

      if ((j + 1) % 3 == 0 and j < 8) {
        rows.push_back(Renderer([&] { return separator(); }));
      }
    }

    inner_board.push_back(Container::Horizontal(rows, &col_sync));

    if ((i + 1) % 3 == 0 and i < 8) {
      inner_board.push_back(Renderer([&] { return separator(); }));
    }
  }

  board_component =
      Container::Horizontal({Container::Vertical(std::move(inner_board))});

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(board_component | border);
  //  game_board.print();

  return 0;
}
