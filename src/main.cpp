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
#include <string>
#include <vector>
using namespace ftxui;

int main(int argc, char *argv[]) {
  // Render board
  Board game_board;
  auto screen = ScreenInteractive::FitComponent();
  int mouse_x = 0, mouse_y = 0;

  int block_size = std::floor(100 / BOARD_SIZE);



  auto game = Renderer([&]() {
    auto c = Canvas(100, 100);

    for (int i = 0; i < BOARD_SIZE; i++) {

      for (int j = 0; j < BOARD_SIZE; j++) {

      int cell_x = i * block_size + (block_size / 2);
      int cell_y = j * block_size + (block_size / 2);

        c.DrawText(cell_x, cell_y, std::to_string(game_board.get(i, j)), [=](Pixel &p) {
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
      mouse_x = e.mouse().x - 1;
      mouse_y = e.mouse().y - 1;
    }
    if (e.mouse().button == Mouse::Left &&
        e.mouse().motion == Mouse::Released) {
      game_board.set(mouse_x, mouse_y, 1);
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

  screen.Loop(component_renderer);

  return 0;
}
