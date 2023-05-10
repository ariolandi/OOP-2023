#ifndef __PIECE__
#define __PIECE__
#include <stdexcept>
#include "chess_square.hpp"

class Piece {
protected:
    Color color;
    int x, y;

    virtual bool can_move(const ChessSquare&) const = 0;

public:
    Piece(const int, const int, const Color);
    virtual ~Piece() = default;

    void move(const ChessSquare&);
    virtual bool can_skip() const;

    virtual Piece* clone() const = 0;
};

Piece::Piece(const int x, const int y, const Color color) : x(x), y(y), color(color) {}

void Piece::move(const ChessSquare& sq) {
    if (can_move(sq)) {
        this->x = sq.x;
        this->y = sq.y;
    }
    else throw std::logic_error("Invalid coordinates");
}

bool Piece::can_skip() const {
    return false;
}

#endif // __PIECE__