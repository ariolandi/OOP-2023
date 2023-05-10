#ifndef __KING__
#define __KING__
#include "piece.hpp"

class King: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    King(const int, const int, const Color);

    virtual Piece* clone() const;
};

bool King::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);
    return (curr.one_offset(other) && (curr.same_row(other) || curr.same_column(other) || curr.diagonal(other)));
}

King::King(const int x, const int y, const Color color): Piece(x, y, color) {}


Piece* King::clone() const {
    return new King(*this);
}



#endif // __KING__