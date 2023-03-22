#include <iostream>
#include <cstring>
#include "jedi.hpp"

void round_fight(Jedi& attacker, Jedi& defender) {
    std::cout << attacker.get_name() << " attacks! " << attacker.attack() << " damage" << std::endl;

    defender.get_damage(attacker.attack());

    if(defender.is_dead()) std::cout << defender.get_name() << " lost!" << std::endl;
}

void fight(Jedi& player1, Jedi& player2) {
    if (player1.get_side() == player2.get_side()) return;

    bool player1_attacks = true;
    while(!player1.is_dead() && !player2.is_dead()) {
        if(player1_attacks) round_fight(player1, player2);
        else round_fight(player2, player1);

        player1_attacks = !player1_attacks; 
    }
}


int main() {
    Jedi good("Good", true);
    Jedi bad("Bad", false);

    fight(good, bad);


    return 0;
}
