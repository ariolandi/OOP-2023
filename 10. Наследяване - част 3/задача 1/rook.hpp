#ifndef __ROOK__
#define __ROOK__
#include "piece.hpp"

class Rook: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    Rook(const int, const int, const Color);

    virtual Piece* clone() const;
};

bool Rook::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);
    return (curr.same_row(other) || curr.same_column(other));
}

Rook::Rook(const int x, const int y, const Color color): Piece(x, y, color) {}


Piece* Rook::clone() const {
    return new Rook(*this);
}



#endif // __ROOK__