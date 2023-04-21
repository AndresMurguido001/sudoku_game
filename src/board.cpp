
#include "board.h"
#include <algorithm>

Board::Board(): board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0)){

}

const int Board::get(int i, int j) const {
    return board[i][j];
}

Board::~Board() {
}

std::ostream& operator<<(std::ostream& os, const Board& game_board) {

    for (int i  = 0; i < BOARD_SIZE; i++) {

        for (int j = 0; j < BOARD_SIZE; j++) {
            os << game_board.get(i, j);
        }

        os << std::endl;
    }
    return os;
}

