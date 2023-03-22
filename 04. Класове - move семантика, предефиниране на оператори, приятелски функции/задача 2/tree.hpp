#ifndef __TREE__
#define __TREE__
#include "../string/string.hpp"

class Tree {
    String species;
    int age;

public:
    Tree(const String, const int);
    // защо нямаме нужда от другите конструктори, оператори за присвояване или деструктр?

    bool operator!=(const Tree&) const;
    bool operator==(const Tree&) const;
    bool operator<(const Tree&) const;
    bool operator>(const Tree&) const;

    void operator++(int);
};

Tree::Tree(const String species = "", const int age = 0): species(species), age(age) {}

bool Tree::operator!=(const Tree& other) const {
    return !(this->species == other.species);       // не съществува предефиниран операто != за String
}

bool Tree::operator==(const Tree& other) const {
    return this->species == other.species && this->age == other.age;
}

bool Tree::operator<(const Tree& other) const {
    return this->species == other.species && this->age < other.age;
}

bool Tree::operator>(const Tree& other) const {
    return this->species == other.species && this->age > other.age;
}

void Tree::operator++(int) {
    this->age++;
}


#endif // __TREE__
