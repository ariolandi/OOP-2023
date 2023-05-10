#ifndef __BISHOP__
#define __BISHOP__
#include "piece.hpp"

class Bishop: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;

public:
    Bishop(const Coordinates&, const Color);

    virtual Piece* clone() const;
};

bool Bishop::can_move(const Coordinates& position) const {
    return this->position.diagonal(position);
}

Bishop::Bishop(const Coordinates& position, const Color color): Piece(position, color) {}


Piece* Bishop::clone() const {
    return new Bishop(*this);
}



#endif // __BISHOP__