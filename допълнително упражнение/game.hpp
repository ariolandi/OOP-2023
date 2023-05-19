#ifndef __GAME__
#define __GAME__
#include "player.hpp"
#include <vector>

const size_t INVALID_INDEX = -1;

class Game {
    Player** players;
    size_t number_of_players;

    void create(const size_t, Player** const);
    void copy(const Game&);
    void clear();

    size_t find_player(const unsigned int) const;
    void clean_unactive();

    void play(const unsigned int);
    void turn();
    bool finalize();

public:
    Game(const size_t, Player** const );
    Game(const Game&);
    Game& operator=(const Game&);
    ~Game();

    void print(const size_t) const;
    void play();
};

void Game::create(const size_t number_of_players, Player** const players) {
    this->number_of_players = number_of_players;
    this->players = new Player*[number_of_players];

    for (size_t i = 0; i < number_of_players; i++) {
        this->players[i] = new Player(*players[i]);
    }
}

void Game::copy(const Game& other){
    create(other.number_of_players, other.players);
}

void Game::clear() {
    for (size_t i = 0; i < number_of_players; i++) {
        if (players[i]) delete players[i];
    }
    
    delete[] players;
}

Game::Game(const size_t number_of_players, Player** const players) {
    create(number_of_players, players);
}

Game::Game(const Game& other) {
    copy(other);
}

Game& Game::operator=(const Game& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Game::~Game() {
    clear();
}

size_t Game::find_player(const unsigned int id) const {
    for (size_t i = 0; i < number_of_players; i++) {
        if (players[i]->get_id() == id) return i;
    }

    return INVALID_INDEX;
}

void Game::clean_unactive() {
    size_t new_number_of_players = number_of_players;

    for (size_t i = 0; i < number_of_players; i++) {
        if (!players[i]->is_active()) {
            delete players[i];
            players[i] = nullptr;
            new_number_of_players--;
        }
    }

    Player** tmp = new Player*[new_number_of_players];
    size_t index = 0;
    for (size_t i = 0; i < number_of_players; i++) {
        if (players[i]) tmp[index++] = players[i];
    }

    delete[] players;
    players = tmp;
    number_of_players = new_number_of_players;
}


void Game::play(const unsigned int index) {
    std::cout << "Player " << players[index]->get_username() << " is in turn!" << std::endl;

    print(index);

    std::cout << "Please choose a player id to play with: " << std::endl;
    size_t choosen_id, choosen_index = INVALID_INDEX;
    while (choosen_index == INVALID_INDEX) {
        std::cout << "> "; std::cin >> choosen_id;

        choosen_index = find_player(choosen_id);
        if (choosen_index == INVALID_INDEX) {
            std::cout << "Please enter a valid player!" << std::endl;
        }
    }

    players[index]->play(*players[choosen_index]);
}

void Game::turn() {
    std::cout << "-- New day! ---" << std::endl;

    for (size_t i = 0; i < number_of_players; i++) play(i);
}

bool Game::finalize() {
    clean_unactive();

    int good = 0, bad = 0;
    
    for (size_t i = 0; i < number_of_players; i++) {
        if (players[i]->alliance() == GOOD) good++;
        else bad++;
    }

    if (good && bad) return false;

    if (good) std::cout << "Hurray! The Good wins again!" << std::endl;
    else std::cout << "Oh, no, the Bad ones win! Better luck next time!" << std::endl;
    return true;
}

void Game::print(const size_t exclude = INVALID_INDEX) const {
    for (size_t i = 0; i < number_of_players; i++) {
        if (i != exclude) players[i]->print();
    }
}

void Game::play() {
    do {
        turn();
    } while (!finalize());
}


#endif // __GAME__
