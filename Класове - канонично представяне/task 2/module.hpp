#ifndef __MODULE__
#define __MODULE__
#include <stdexcept>
#include "spaceship.hpp"
const int INVALID_INDEX = -1;

class Module {
    int capacity;
    SpaceShip** parkinglot;

    void copy(const Module&);
    void delete_module();

    int find_empty_place() const;
public:
    Module(const int);
    Module(const Module&);
    Module& operator=(const Module&);
    ~Module();

    void park(const SpaceShip&);
    void departure(const char*);
    bool empty() const;
};

void Module::copy(const Module& other) {
    this->capacity = other.capacity;
    this->parkinglot = new SpaceShip*[this->capacity];

    for (int i = 0; i < this->capacity; i++) {
        this->parkinglot[i] = other.parkinglot[i] ? new SpaceShip(*other.parkinglot[i]) : nullptr;
    } 
}

void Module::delete_module() {
    for (int i = 0; i < this->capacity; i++) {
        if (this->parkinglot[i]) delete this->parkinglot[i];
    }

    delete[] this->parkinglot;
}

Module::Module(const int capacity) {
    this->capacity = capacity;
    this->parkinglot = new SpaceShip*[capacity];

    for (int i = 0; i < capacity; i++) {
        this->parkinglot[i] = nullptr;
    }
}

Module::Module(const Module& other) {
    copy(other);
}

Module& Module::operator=(const Module& other) {
    if (this != &other) {
        delete_module();
        copy(other);
    }

    return *this;
}

Module::~Module() {
    delete_module();
}

int Module::find_empty_place() const {
    for (int i = 0; i < capacity; i++) {
        if (!parkinglot[i]) return i;
    }

    return INVALID_INDEX;
}

void Module::park(const SpaceShip& new_spaceship) {
    int index = find_empty_place();

    if (index == INVALID_INDEX) throw std::logic_error("No available space");
    
    parkinglot[index] = new SpaceShip(new_spaceship);
}

void Module::departure(const char* spaceship_codename) {
    for (int i = 0; i < capacity; i++) {
        if (parkinglot[i] && parkinglot[i]->get_codename() == spaceship_codename) {
            delete parkinglot[i];
            parkinglot[i] = nullptr;
            return;
        }
    }

    throw std::logic_error("This spaceship is not found!");
}

bool Module::empty() const {
    for (int i = 0; i < capacity; i++) {
        if (parkinglot[i]) return false;
    }

    return true;
}


#endif // __MODULE__
