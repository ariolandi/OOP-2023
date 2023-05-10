#ifndef __BISHOP__
#define __BISHOP__
#include "piece.hpp"

class Bishop: public Piece {
protected:
    virtual bool can_move(const ChessSquare&) const;

public:
    Bishop(const int, const int, const Color);

    virtual Piece* clone() const;
};

bool Bishop::can_move(const ChessSquare& other) const {
    ChessSquare curr(this->x, this->y);
    return curr.diagonal(other);
}

Bishop::Bishop(const int x, const int y, const Color color): Piece(x, y, color) {}


Piece* Bishop::clone() const {
    return new Bishop(*this);
}



#endif // __BISHOP__