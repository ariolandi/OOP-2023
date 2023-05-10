#ifndef __KING__
#define __KING__
#include "piece.hpp"

class King: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;

public:
    King(const Coordinates&, const Color);

    virtual Piece* clone() const;
};

bool King::can_move(const Coordinates& position) const {
    return (this->position.one_offset(position) && 
            (this->position.same_row(position) || 
             this->position.same_column(position) || 
             this->position.diagonal(position))
            );
}

King::King(const Coordinates& position, const Color color): Piece(position, color) {}


Piece* King::clone() const {
    return new King(*this);
}



#endif // __KING__