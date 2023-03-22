#ifndef __COURSE__
#define __COURSE__
#include "../string/string.hpp"
#include "student.hpp"
const int INVALID_INDEX = -1;

class Course {
    String name;
    String description;
    Student** students;
    int students_count;

    void copy_students(Student** const, const int);
    void copy(const Course&);
    void copy(Course&&);
    void delete_students();

    int find_student(const int) const;

public:
    Course(const String&, const String&, Student** const, const int);
    Course(const Course&);
    Course(Course&&);
    Course& operator=(const Course&);
    Course& operator=(Course&&);
    ~Course();

    const Student& operator[](const int) const;             // ще се използва при извикване от константен обект
    Student& operator[](const int);                         // ще се използва във всички други случаи и ще разреши промяна на студента
};

void Course::copy_students(Student** const students, const int students_count) {
    if (!students) {
        this->students_count = 0;
        this->students = nullptr;
        return;
    }

    this->students_count = students_count;
    this->students = new Student*[students_count];

    for (int i = 0; i < students_count; i++) {
        // винаги може да бъде подаден nullptr и трябва да се предвиди това
        if (students[i]) this->students[i] = new Student(*students[i]);
        else this->students[i] = nullptr;
    }
}

void Course::copy(const Course& other) {
    this->name = other.name;
    this->description = other.description;
    copy_students(other.students, other.students_count);
}

void Course::copy(Course&& other) {
    this->name = other.name;
    this->description = other.description;
    this->students_count = other.students_count;
    this->students = other.students;

    other.students = nullptr;
    other.students_count = 0;
    other.description = "";
    other.name = "";
}

void Course::delete_students() {
    if (!students) return;

    for (int i = 0; i < students_count; i++) {
        if (students[i]) delete students[i];
    }

    delete[] students;
}

int Course::find_student(const int student_fn) const {
    for (int i = 0; i < students_count; i++) {
        if (students[i] && students[i]->get_fn() == student_fn) return i;
    }

    return INVALID_INDEX;
}


Course::Course(const String& name = "", const String& description = "", 
               Student** const students = nullptr, const int students_count = 0): name(name), description(description) {
    copy_students(students, students_count);
}

Course::Course(const Course& other) {
    copy(other);
}

Course::Course(Course&& other) {
    copy((Course&&) other);
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        delete_students();
        copy(other);
    }

    return *this;
}

Course& Course::operator=(Course&& other) {
    if (this != &other) {
        delete_students();
        copy((Course&&) other);
    }

    return *this;
}

Course::~Course() {
    delete_students();
}

const Student& Course::operator[](const int student_fn) const {
    int index = find_student(student_fn);

    if (index == INVALID_INDEX) throw std::runtime_error("There is no such student!");

    return *students[index];
}

Student& Course::operator[](const int student_fn) {
    int index = find_student(student_fn);

    if (index == INVALID_INDEX) throw std::runtime_error("There is no such student!");

    return *students[index];
}    


#endif // __COURSE__