#ifndef __CHESS_SQUARE__
#define __CHESS_SQUARE__
#include <cmath>

class Piece;

enum Color{white, black};

// x - row, y - column
struct ChessSquare {
    int x, y;
    Piece* has_piece;

    ChessSquare(const int x, const int y): 
        x(x), y(y), has_piece(nullptr) {}

    int column_offset(const ChessSquare& other) const {
        return abs(y - other.y);
    }

    int row_offset(const ChessSquare& other) const {
        return abs(x - other.x);
    }

    bool same_column(const ChessSquare& other) const {
        return (y == other.y);
    }

    bool same_row(const ChessSquare& other) const {
        return (x == other.x);
    }

    bool one_offset(const ChessSquare& other) const {
        int x_diff = row_offset(other);
        int y_diff = column_offset(other);
        return (x_diff <= 1 || y_diff <= 1);
    }

    bool forward(const ChessSquare& other, const Color& color) const {
        return (color == Color::white) ? (x < other.x) : (other.x < x);
    }

    bool diagonal(const ChessSquare& other) const {
        int x_diff = row_offset(other);
        int y_diff = column_offset(other);
        return (x_diff == y_diff);
    }

    bool knight_move(const ChessSquare& other) const {
        int x_diff = row_offset(other);
        int y_diff = column_offset(other);
        return ((x_diff == 2 && y_diff == 1) || (x_diff == 1 && y_diff == 2));
        // return (x_diff != 0 && y_diff != 0 && x_diff + y_diff == 3);
    }
};

#endif // __CHESS_SQUARE__