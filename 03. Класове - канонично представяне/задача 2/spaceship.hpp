#ifndef __SPACESHIP__
#define __SPACESHIP__
#include "../task 1/string.hpp"

class SpaceShip {
    String codename;
    int crew_count;
    int fluel_capacity;

public:
    SpaceShip(const String&, const int, const int);

    const String &get_codename() const { return codename; };
};


SpaceShip::SpaceShip(const String& codename, const int crew_count, const int fluel_capacity) {
    this->codename = codename;
    this->crew_count = crew_count;
    this->fluel_capacity = fluel_capacity;
}


#endif // __SPACESHIP__