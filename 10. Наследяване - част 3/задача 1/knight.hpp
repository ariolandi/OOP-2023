#ifndef __KNIGHT__
#define __KNIGHT__
#include "piece.hpp"

class Knight: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    Knight(const int, const int, const Color);

    virtual bool can_skip() const;

    virtual Piece* clone() const;
};

bool Knight::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);
    return curr.knight_move(other);
}

Knight::Knight(const int x, const int y, const Color color): Piece(x, y, color) {}

bool Knight::can_skip() const {
    return true;
}

Piece* Knight::clone() const {
    return new Knight(*this);
}



#endif // __KNIGHT__