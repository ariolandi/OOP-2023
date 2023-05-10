#ifndef __PIECE__
#define __PIECE__
#include <stdexcept>
#include "coordinates.hpp"


class Piece {
protected:
    Color color;
    Coordinates position;

    virtual bool can_move(const Coordinates&) const = 0;
    virtual bool can_attack(const Coordinates&) const;

public:
    Piece(const Coordinates&, const Color);
    virtual ~Piece() = default;

    void move(const Coordinates&, const bool);
    virtual bool can_skip() const;

    virtual Piece* clone() const = 0;
};

Piece::Piece(const Coordinates& position, const Color color): position(position), color(color) {}

void Piece::move(const Coordinates& position, const bool attack = false) {
    if (attack ? can_attack(position) : can_move(position)) {
        this->position = position;
    }
    else throw std::logic_error("Invalid coordinates");
}

bool Piece::can_attack(const Coordinates& position) const {
    can_move(position);
}

bool Piece::can_skip() const {
    return false;
}

#endif // __PIECE__