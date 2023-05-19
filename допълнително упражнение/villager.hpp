#ifndef __VILLAGER__
#define __VILLAGER__
#include "role.hpp"

class Villager: public Role {
public:
    Villager(): Role(GOOD) {}
    void play(Role* other) const {}

    Role* clone() const { return new Villager(*this); }

};

#endif // __VILLAGER__
