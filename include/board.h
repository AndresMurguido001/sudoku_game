#ifndef BOARD_H
#define BOARD_H

#include <ftxui/dom/canvas.hpp>
#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <array>

const int BOARD_SIZE = 9;

struct Cell {



};

// Board should contain cells and state of game;
class Board 
{
public:
    Board();
    ~Board();
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> board;
    const int get(int, int) const;
    void set(int, int, int);
    void print();
    void update_color(int, int);

private:
    void make_grid(int, int);
    
};

#endif
