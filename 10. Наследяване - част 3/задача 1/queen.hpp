#ifndef __QUEEN__
#define __QUEEN__
#include "piece.hpp"

class Queen: public Piece {
protected:
    virtual bool can_move(const Coordinates&) const;

public:
    Queen(const Coordinates&, const Color);

    virtual Piece* clone() const;
};

bool Queen::can_move(const Coordinates& position) const {
    return (this->position.same_row(position) || 
            this->position.same_column(position) || 
            this->position.diagonal(position));
}

Queen::Queen(const Coordinates& position, const Color color): Piece(position, color) {}


Piece* Queen::clone() const {
    return new Queen(*this);
}



#endif // __QUEEN__