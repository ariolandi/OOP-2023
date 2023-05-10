#include <iostream>
#include <fstream>
#include <string>
#include "student.hpp"
using std::cin, std::cout, std::endl, std::string;


int main () {
    Student g;
    cin >> g;
    std::ofstream fout(g.get_filename());
    if(fout) {
        cout << "file open" << endl;
        fout << g;
        fout.close();
    }


    return 0;
}