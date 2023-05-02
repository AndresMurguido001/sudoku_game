#include "board.h"
#include <algorithm>
#include <cstddef>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <vector>
using namespace ftxui;

int main(int argc, char *argv[]) {
  // Render board
  Board game_board;
  int mouse_x = 0, mouse_y = 0;

  auto board = game_board.board;

  auto game = Renderer([&]() {
    auto c = Canvas(BOARD_SIZE * 2, BOARD_SIZE * 4);

    for (int i = 0; i < BOARD_SIZE; i++) {

      for (int j = 0; j < BOARD_SIZE; j++) {

        c.DrawText(i * 2, j * 4, std::to_string(board[i][j]), [=](Pixel &p) {
          if (mouse_x == i && mouse_y == j) {
            p.foreground_color = Color::Red;
          } else {
            p.foreground_color = Color::White;
          }
        });
      }
    }

    return canvas(std::move(c));
  });

  auto container = Container::Vertical({game});

  auto container_w_mouse = CatchEvent(container, [&](Event e) {
    if (e.is_mouse()) {
      mouse_x = (e.mouse().x - 1) * 2;
      mouse_y = (e.mouse().y - 1) * 4;
    }
    return false;
  });

  auto c = Container::Vertical({container_w_mouse});

  auto component_renderer = Renderer(c, [&] {
    return vbox({
               container_w_mouse->Render(),
           }) |
           border;
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(component_renderer);

  return 0;
}
