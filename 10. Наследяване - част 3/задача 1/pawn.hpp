#ifndef __PAWN__
#define __PAWN__
#include "piece.hpp"
#include <iostream>

class Pawn: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    Pawn(const int, const int, const Color);
    Piece* clone() const;
};


bool Pawn::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);

    if (curr.one_offset(other) && curr.forward(other, this->color)) {
        if (other.has_piece) {
            return curr.diagonal(other);
        } 
        return curr.same_column(other);
    }
    return false;
}


Pawn::Pawn(const int x, const int y, const Color color): Piece(x, y, color) {}

Piece* Pawn::clone() const {
    return new Pawn(*this);
}


#endif // __PAWN__