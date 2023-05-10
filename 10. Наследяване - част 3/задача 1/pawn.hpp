#ifndef __PAWN__
#define __PAWN__
#include "piece.hpp"
#include <iostream>

class Pawn: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;
    virtual bool can_attack(const Coordinates&) const;

public:
    Pawn(const Coordinates&, const Color);
    Piece* clone() const;
};


bool Pawn::can_move(const Coordinates& position) const {
    return (this->position.one_offset(position) && 
            this->position.forward(position, this->color) && 
            this->position.same_column(position));
}

bool Pawn::can_attack(const Coordinates& position) const {
    return (this->position.one_offset(position) && 
            this->position.forward(position, this->color) && 
            this->position.diagonal(position));
}


Pawn::Pawn(const Coordinates& Coordinates, const Color color): Piece(Coordinates, color) {}

Piece* Pawn::clone() const {
    return new Pawn(*this);
}


#endif // __PAWN__