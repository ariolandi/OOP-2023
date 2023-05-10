#ifndef __KNIGHT__
#define __KNIGHT__
#include "piece.hpp"

class Knight: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;

public:
    Knight(const Coordinates& , const Color);

    virtual bool can_skip() const;

    virtual Piece* clone() const;
};

bool Knight::can_move(const Coordinates& position) const {
    return this->position.knight_move(position);
}

Knight::Knight(const Coordinates&  position, const Color color): Piece(position, color) {}

bool Knight::can_skip() const {
    return true;
}

Piece* Knight::clone() const {
    return new Knight(*this);
}



#endif // __KNIGHT__