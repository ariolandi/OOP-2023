#ifndef __CHESS_SQUARE__
#define __CHESS_SQUARE__
#include <cmath>
#include "piece.hpp"

struct ChessSquare {
    Coordinates position;
    Piece* has_piece;

    ChessSquare(const Coordinates& position): 
        position(position), has_piece(nullptr) {}
};

#endif // __CHESS_SQUARE__