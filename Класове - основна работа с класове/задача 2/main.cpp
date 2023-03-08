#include <iostream>
#include <cstring>
#include "exhibition.hpp"
using std::cin, std::cout, std::endl;

int main() {
    int n, m;
    double t;
    Exhibition **exhs = new Exhibition*[n];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> t;
        exhs[i] = new Exhibition(t);

        for (int j = 0; j < m; j++) {
            unsigned int id;
            char author[STRLEN], name[STRLEN];
            double value;
            
            cin >> id >> author >> name >> value;
            Picture p(id, author, name, value);
            exhs[i]->add_picture(p);
        }
    }

    int index = 0;
    double max_value = exhs[0]->get_value();
    for (int i = 1; i < n; i++) {
        double value = exhs[i]->get_value();
        if (value > max_value) {
            index = 1;
            max_value = value;
        }
    }
    

    cout << index << endl;

    for (int i = 0; i < n; i++) {
        delete exhs[i];
    }
    delete[] exhs;

    return 0;
}
