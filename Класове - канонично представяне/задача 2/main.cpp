#include <iostream>
#include "spaceship.hpp"
#include "module.hpp"
#include "spacestation.hpp"
using std::cin, std::cout, std::endl;

int main() {
    String str("Spaceship1");

    SpaceShip ss(str, 1, 3);
    cout << ss.get_codename().get() << endl;

    SpaceShip many[2] = {SpaceShip("spaceship2", 4, 15), SpaceShip("fjfhd", 4, 30)};

    Module m(5);
    m.park(ss);
    m.departure("Spaceship1");

    SpaceStation s(1, 1);
    s.land(ss);
    s.land(many, 2);
    s.departure("Soaceship3");
    

    return 0;
}