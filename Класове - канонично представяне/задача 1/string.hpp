#ifndef _STRING_
#define _STRING_
#include <cstring>

class String {
    char *str;

    void create(const char*);
    void copy(const String&);
    void delete_str();

    String add_str(const char*) const;
public:
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();

    const char* get() const { return str; }
    int size() const { return strlen(str); }

    bool operator==(const String&) const;
    String operator+(const String&) const;
    String operator+(const char*) const;
    void operator+=(const String&);
    void operator+=(const char*);
};



String::String(const char* str = "") {
   create(str);
}

String::String(const String& other) {
    copy(other);
}

String& String::operator=(const String& other) {
    if (this != &other) {                   // проверка дали случайно не сме подали същия обект
        delete_str();
        copy(other);
    }

    return *this;                           // връщане на референция към текущия обект
}

String::~String(){
    delete_str();
}

bool String::operator==(const String& other) const {
    return !strcmp(this->str, other.str);
}

String String::operator+(const String& other) const {
    return add_str(other.str);
}

String String::operator+(const char* other) const {
    return add_str(other);
}

void String::operator+=(const String& other) {
    operator=(operator+(other));
}

void String::operator+=(const char* other) {
    operator+=(String(other));
}

void String::create(const char* str) {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str); 
}

void String::copy(const String& other) {
    create(other.str);
}

void String::delete_str() {
    delete[] str;
}

String String::add_str(const char* str) const {
    char *tmp = new char[strlen(this->str) + strlen(str) + 1];
    strcpy(tmp, this->str);             // tmp == this->str;
    strcat(tmp, str);                   // tmp == this->str + str

    String to_return(tmp);
    delete[] tmp;                       // изтриваме помощната динамична памет преди да върнем резултат
    return to_return;
}




#endif // _STRING_
