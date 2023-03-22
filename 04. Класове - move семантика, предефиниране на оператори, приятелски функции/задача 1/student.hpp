#ifndef __STUDENT__
#define __STUDENT__
#include <cstring>

class Student {
    char* name;
    int fn;

    void set_name(const char*);
    void delete_name();
    void copy(const Student&);
    void copy(Student&&);

public:
    Student(const char*, const int);
    Student(const Student&);
    ~Student();
    Student& operator=(const Student&);

    Student(Student&&);
    Student& operator=(Student&&);

    const char* get_name() const { return name; }
    const int get_fn() const { return fn; }
};


void Student::set_name(const char* name) {
    if(!name) this->name = nullptr; // nullptr
    else {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Student::delete_name() {
    if (name) delete[] name;
}

void Student::copy(const Student& other) {
    this->fn = other.fn;
    set_name(other.name);
}

void Student::copy(Student&& other) {
    this->name = other.name;
    this->fn = other.fn;

    other.name = nullptr;
}

Student::Student(const char* name = nullptr, const int fn = 0): fn(fn) {
    set_name(name);
}

Student::Student(const Student& other) {
    copy(other);
}

Student::~Student() {
    delete_name();
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete_name();
        copy(other);
    }

    return *this;
}

Student::Student(Student&& other) {
    copy((Student&&) other);
}

Student& Student::operator=(Student&& other) {
    if (this != &other) {
        delete_name();
        copy((Student&&) other);
    }

    return *this;
}



#endif