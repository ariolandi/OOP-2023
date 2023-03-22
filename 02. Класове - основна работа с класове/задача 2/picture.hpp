#ifndef __PICTURE__
#define __PICTURE__
#include <cstring>
const int STRLEN = 101;


class Picture {
    unsigned int id;
    char name[STRLEN];
    char author[STRLEN];
    double value;

public:
    Picture(const unsigned int id, const char* author, const char* name, const double value);

    double get_value() const;
};

Picture::Picture(const unsigned int id = 0, const char* author = "", const char* name = "", const double value = 0) {
    this->id = id;
    strcpy(this->name, name);
    strcpy(this->author, author);
    this->value = value;
}

double Picture::get_value() const {
    return value;
}



#endif // __PICTURE__
