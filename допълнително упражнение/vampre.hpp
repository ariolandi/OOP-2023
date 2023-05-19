#ifndef __VAMPRE__
#define __VAMPRE__
#include "role.hpp"

class Vampire: public Role {
public:
    Vampire(): Role(BAD) {}
    void play(Role*) const;

    Role* clone() const { return new Vampire(*this); }

};

void Vampire::play(Role* other) const {
    other->injure();
}

#endif // __VAMPRE__
