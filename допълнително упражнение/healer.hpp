#ifndef __HEALER__
#define __HEALER__
#include "role.hpp"

class Healer: public Role {
public:
    Healer(): Role(GOOD) {}
    void play(Role*) const;

    Role* clone() const { return new Healer(*this); }
};

void Healer::play(Role* other) const {
    if (other->dying()) other->heal();
}

#endif // __HEALER__
