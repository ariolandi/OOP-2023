#include <fstream>
#include "student.hpp"

class SUSI {
    Student students[100];
    std::string subjects[100];
    int student_size;
    int subject_size;
    std::string students_filename;
    std::string subjects_filename;

public:
    SUSI(const std::string& students_filename, const std::string subjects_filename): 
students_filename(students_filename), subjects_filename(subjects_filename), student_size(0), subject_size(0) {
        std::ifstream fin(students_filename);

        while(fin >> students[student_size]) student_size++;

        fin.close();
        fin.open(subjects_filename);
        
        while(fin >> subjects[subject_size]) subject_size++;

        fin.close();
    }

    ~SUSI() {
        // записваме всички файлове за студенти
    }

    void add_student(const Student&) {
        // записваме във файл student_filename
    }

    void add_subject_to_student(int fn, const std::string subject) {
        // валидация
        // намери студент -> добави предмет
    }
};