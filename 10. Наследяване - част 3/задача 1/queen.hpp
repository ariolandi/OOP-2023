#ifndef __QUEEN__
#define __QUEEN__
#include "piece.hpp"

class Queen: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    Queen(const int, const int, const Color);

    virtual Piece* clone() const;
};

bool Queen::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);
    return (curr.same_row(other) || curr.same_column(other) || curr.diagonal(other));
}

Queen::Queen(const int x, const int y, const Color color): Piece(x, y, color) {}


Piece* Queen::clone() const {
    return new Queen(*this);
}



#endif // __QUEEN__