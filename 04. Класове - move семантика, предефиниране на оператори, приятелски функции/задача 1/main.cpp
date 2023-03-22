#include <iostream>
#include "student.hpp"
using std::cin, std::cout, std::endl;

int main() {
    Student s(Student("fjhf", 13));
    s = Student("Gosho", 34);

    cout << s.get_name() << endl;

    return 0;
}
