#include <iostream>
#include "forest.hpp"

int main () {
    int n = 2;
    Tree** t = new Tree*[n];
    for (int i = 0; i < n; i++) {
        t[i] = new Tree();
    }

    Forest f((const Tree**)t, n);
    Forest fu = unique(f);


    for (int i = 0; i < n; i++) {
        delete t[i];
    }

    delete[] t;

    return 0;
}