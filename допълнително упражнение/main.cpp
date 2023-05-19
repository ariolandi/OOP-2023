#include <iostream>
#include "vampre.hpp"
#include "seer.hpp"
#include "healer.hpp"
#include "villager.hpp"
#include "player.hpp"
#include "game.hpp"
#include <ctime>
#include <cstdlib>
#include <vector>

int random(const unsigned int max) {
    srand(time(NULL));
    return rand() % max;
}

template <typename T, typename U>
struct Pair {
    T first;
    U second;
};


// for testing purposes
class GameGenerator {

    inline static const int MINIMUM_PLAYERS = 4;
    inline static const int MAXIMUM_PLAYERS = 12;

    inline static const Vampire vampire;
    inline static const Seer seer;
    inline static const Healer healer;
    inline static const Villager villager;

    inline static Pair<const Role*, int> statistics[4];

    static void set_statistics(const unsigned n) {
        int seers = 1;
        int healers = 1;
        int vampires = n / 3; // 30% bad guys
        int villagers = n - vampires - seers - healers;

        statistics[0] = {&vampire, vampires}; 
        statistics[1] = {&seer, seers};
        statistics[2] = {&healer, healers};
        statistics[3] = {&villager, villagers};

    }

    static const Role* generate_role() {     
        while(true) {
            int x = random(4);
            if (statistics[x].second > 0) {
                statistics[x].second--;
                return statistics[x].first;
            }
        }
    }

public:
    static Game generate_game(const unsigned n) {
        if (n < MINIMUM_PLAYERS || n > MAXIMUM_PLAYERS) throw std::logic_error("Invalid number of players!");

        set_statistics(n);

        Player** p = new Player*[n];
        for (size_t i = 0; i < n; i++) {
            std::string name;

            std::cout << "Please enter username: "; 
            std::cin >> name;

            p[i] = new Player(name, GameGenerator::generate_role());
        }

        return Game(n, p);
    }
};


int main () {
    Game g = GameGenerator::generate_game(6);
    g.play();

    return 0;
}