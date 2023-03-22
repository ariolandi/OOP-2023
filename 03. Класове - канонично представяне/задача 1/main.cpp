#include <iostream>
#include <cstring>
#include "string.hpp"
using std::cin, std::cout, std::endl;

int main () {
    String s1("fjhfhd");      // constructor
    String s2("abvcs");       // default constr

    String s3 = s1 + s2;      // copy constr
    cout << s1.get() << endl << s2.get() << endl << s3.get() << endl;
    s1 = s2 + "toitugn";      // operator =
    cout << s1.get() << endl;



    return 0;
}                            // destr