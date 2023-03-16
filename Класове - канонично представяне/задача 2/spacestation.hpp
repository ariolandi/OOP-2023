#ifndef __SPACESTATION__
#define __SPACESTATION__
#include "spaceship.hpp"
#include "module.hpp"

class SpaceStation {
    int module_count;
    int module_size;
    Module **modules;

    void copy(const SpaceStation&);
    void delete_modules();

    void add_module();
    void delete_module(const int);
public:
    SpaceStation(const int, const int);
    SpaceStation(const SpaceStation&);
    SpaceStation& operator=(const SpaceStation&);
    ~SpaceStation();

    void land(const SpaceShip&);
    void land(const SpaceShip*, const int);
    void departure(const char*);
};


void SpaceStation::copy(const SpaceStation& other) {
    this->module_count = other.module_count;
    this->module_size = other.module_size;

    modules = new Module*[this->module_count];

    for (int i = 0; i < this->module_count; i++) {
        modules[i] = new Module(*other.modules[i]);
    }
}

void SpaceStation::delete_modules() {
    for (int i = 0; i < module_count; i++) {
        delete modules[i];
    }

    delete[] modules;
}

void SpaceStation::add_module() {
    Module** tmp = new Module*[module_count + 1];
    
    for(int i = 0; i < module_count; i++) {
        tmp[i] = new Module(*modules[i]);
    }

    tmp[module_count] = new Module(module_size);
    module_count++;

    delete_modules();
    modules = tmp;
}

void SpaceStation::delete_module(const int index) {
    Module** tmp = new Module*[module_count - 1];
    int tmp_index = 0;

    for(int i = 0; i < module_count; i++) {
        if (i != index) {
            tmp[tmp_index] = new Module(*modules[i]);
            tmp_index++;
        }
    }

    module_count--;

    delete_modules();
    modules = tmp;
}

SpaceStation::SpaceStation(const int module_count, const int module_size) {
    this->module_count = module_count;
    this->module_size = module_size;

    modules = new Module*[this->module_count];

    for (int i = 0; i < this->module_count; i++) {
        modules[i] = new Module(this->module_size);
    }
}

SpaceStation::SpaceStation(const SpaceStation& other) {
    copy(other);
}

SpaceStation& SpaceStation::operator=(const SpaceStation& other) {
    if (this != &other) {
        delete_modules();
        copy(other);
    } 

    return *this;
}

SpaceStation::~SpaceStation() {
    delete_modules();
}

void SpaceStation::land(const SpaceShip& new_spaceship) {
    for (int i = 0; i < module_count; i++) {
        try {
            modules[i]->park(new_spaceship);
            return;
        } catch (std::logic_error e) {}
    }

    add_module();
    modules[module_count - 1]->park(new_spaceship);
}

void SpaceStation::land(const SpaceShip* division, const int count) {
    for (int i = 0; i < count; i++) {
        land(division[i]);
    }
}

void SpaceStation::departure(const char* spaceship_name) {
    for (int i = 0; i < module_count; i++) {
        try {
            modules[i]->departure(spaceship_name);
            if (modules[i]->empty()) {
                delete_module(i);
            }
            return;
        } catch (std::logic_error e) {}
    }
}




#endif // __SPACESTATION__