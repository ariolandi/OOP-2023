#include <iostream>
#include "student.hpp"
#include "course.hpp"
using std::cin, std::cout, std::endl;

int main() {
    Student s(Student("Ivan", 13));
    Student s1 = Student("Gosho", 34);

    int n = 2;
    Student* students[2] = {&s, &s1};

    Course c(String("jdhd"), String("fjfh fkhf"), students, n);
    Student cs = c[13];
    cout << cs.get_name() << endl;
    c[13] = Student("Anya", 21);
    cs = c[13]; // error - not such student, защото този студент вече е с fn 21

    return 0;
}
