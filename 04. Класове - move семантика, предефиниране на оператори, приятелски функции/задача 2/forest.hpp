#ifndef __FOREST__
#define __FOREST__
#include <utility>
#include "tree.hpp"

class Forest {
    Tree** trees;
    int size;

    void create(const Tree**, const int);
    void copy(const Forest&);
    void copy(Forest&&);
    void delete_forest();

    void resize(const int);
public:
    Forest();
    Forest(const Tree**, const int);
    Forest(const Forest&);
    Forest(Forest&&);
    Forest& operator=(const Forest&&);
    Forest& operator=(Forest&&);
    ~Forest();

    void operator+=(const Tree&);
    void operator--(int);

    friend Forest unique(const Forest&);
};
void Forest::create(const Tree** trees, const int size) {
    if (!trees) {
        this->size = 0;
        this->trees = nullptr;
        return;
    }

    this->size = size;
    this->trees = new Tree*[size];

    for (int i = 0; i < size; i++) {
        this->trees[i] = (trees[i] ? new Tree(*trees[i]) : nullptr);
    }
}

void Forest::copy(const Forest& other) {
    create((const Tree**) other.trees, other.size);
}

void Forest::copy(Forest&& other) {
    this->trees = other.trees;
    this->size = other.size;

    other.trees = nullptr;
    other.size = 0;
}

void Forest::delete_forest() {
    for (int i = 0; i < size; i++) {
        if (trees[i]) delete trees[i];
    }

    delete[] trees;
}

void Forest::resize(const int new_size) {
    Tree **tmp = new Tree*[new_size];

    for (int i = 0; i < size; i++) {
        tmp[i] = (trees[i] ? new Tree(*trees[i]) : nullptr);
    }

    delete_forest();
    trees = tmp;
    size = new_size;
}

Forest::Forest(): trees(nullptr), size(0) {}

Forest::Forest(const Tree** trees, const int size) {
    create(trees, size);
}

Forest::Forest(const Forest& other) {
    copy(other);
}

Forest::Forest(Forest&& other) {
    copy(std::move(other));
}

Forest& Forest::operator=(const Forest&& other) {
    if (this != &other) {
        delete_forest();
        copy(other);
    }

    return *this;
}

Forest& Forest::operator=(Forest&& other) {
    if (this != &other) {
        delete_forest();
        copy(std::move(other));
    }

    return *this;
}

Forest::~Forest() {
    delete_forest();
}

void Forest::operator+=(const Tree& new_tree) {
    resize(size + 1);
    trees[size - 1] = new Tree(new_tree);       // последният елемент се очаква да е nullptr
}

void Forest::operator--(int) {
    resize(size - 1);                           // последното дърво ще бъде изтрито от resize
}

Forest unique(const Forest& forest) {
    Forest unique_forest;

    for (int i = 0; i < forest.size; i++) {
        bool to_be_added = true;
        for (int j = 0; j < unique_forest.size && to_be_added; j++) {
            to_be_added = !(forest.trees[i] == unique_forest.trees[j]); // да се отбележи, че операторите == и != са за класа Tree семантично различни по условие
        }

        if (to_be_added) unique_forest += *(forest.trees[i]);
    }

    return unique_forest;
}

#endif // __FOREST__