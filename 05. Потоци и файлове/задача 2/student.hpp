#ifndef __STUDENT__
#define __STUDENT__
#include "../string/string.hpp"
#include <string>
const std::string PATH = ".";

class Student {
    std::string name;
    std::string surname;
    int fn;
    std::string subjects[100];
    int size;

public:
    Student(const std::string& name = "", const std::string& surname = "", const int fn = 0):
    name(name), surname(surname), fn(fn), size(0) {}

    void add_subject(const std::string& subject) {
        subjects[size] = subject;
        size++;
    }

    std::string get_filename() const { return PATH + "/" + name + "_" + surname + ".txt"; }

    friend std::ostream& operator<<(std::ostream&, const Student&);
    friend std::istream& operator>>(std::istream&, Student&);
};

std::ostream& operator<<(std::ostream& os, const Student& object) {
    os << object.name << " " << object.surname << " " << object.fn << std::endl;
    for (int i = 0; i < object.size; i++) {
        os << object.subjects[i] << std::endl;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Student& object) {
    is >> object.name >> object.surname >> object.fn;
    is >> object.size;
    for (int i = 0; i < object.size; i++) {
        is >> object.subjects[i];
    }

    return is;
}


#endif // __STUDENT__
