#ifndef __SEER__
#define __SEER__
#include "role.hpp"

class Seer: public Role {
public:
    Seer(): Role(GOOD) {}
    void play(Role*) const;

    Role* clone() const { return new Seer(*this); }
};

void Seer::play(Role* other) const {
    if (!other->is_good()) other->kill();
}

#endif // __SEER__
