#ifndef __PLAYER__
#define __PLAYER__
#include "vampre.hpp"
#include "seer.hpp"
#include "healer.hpp"
#include "villager.hpp"
#include <string>
#include <iostream>


class Player {
    static unsigned int ID;

    unsigned int id;
    std::string username;
    Role* role;

    void set(const std::string&, const Role*, const unsigned int);

    void copy(const Player&);
    void clear();

public:
    Player(const std::string&, const Role*);
    Player(const Player&);
    Player& operator=(const Player&);
    ~Player();

    void play(Player& other) { role->play(other.role); }
    bool is_active() const { return (role->is_alive() && !role->dying()); }
    bool alliance() const { return role->is_good(); }
    unsigned int get_id() const { return id; }
    const std::string get_username() const { return username; }

    void print() const;
};

unsigned int Player::ID = 1;

void Player::set(const std::string& username, const Role* role, const unsigned int id) {
    this->role = role->clone();
    this->username = username;
    this->id = id;
}

void Player::copy(const Player& other) {
    set(other.username, other.role, other.id);
}

void Player::clear() {
    delete role;
}

Player::Player(const std::string& username, const Role* role) {
    set(username, role, ID);
    ID++;
}

Player::Player(const Player& other) {
    copy(other);
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Player::~Player() {
    clear();
}

void Player::print() const {
    std::cout << id << ": " << username << (role->dying() ? " *" : "") << std::endl;
}


#endif // __PLAYER__
