#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
const int BOARD_SIZE = 9;

class Board
{
public:
    friend std::ostream& operator<<(std::ostream& os, const Board& game_board);
    Board();
    ~Board();
    const int get(int, int) const;

private:
    std::vector<std::vector<int>> board;
    
};

#endif
