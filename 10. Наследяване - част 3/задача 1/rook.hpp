#ifndef __ROOK__
#define __ROOK__
#include "piece.hpp"

class Rook: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;

public:
    Rook(const Coordinates&, const Color);

    virtual Piece* clone() const;
};

bool Rook::can_move(const Coordinates& position) const {
    return (this->position.same_row(position) || this->position.same_column(position));
}

Rook::Rook(const Coordinates& position, const Color color): Piece(position, color) {}


Piece* Rook::clone() const {
    return new Rook(*this);
}



#endif // __ROOK__