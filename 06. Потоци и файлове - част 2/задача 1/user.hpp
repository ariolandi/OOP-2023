#ifndef __USER__
#define __USER__
#include <cstring>
#include <iostream>
#include <fstream>

class User {
    char username[50];
    char password[50];
    bool admin;

public:
    User(const char* username = "", const char* password = ""): admin(false) {
        strcpy(this->username, username);
        strcpy(this->password, password);
    }

    bool operator==(const User& other) const {
        return (!strcmp(this->username, other.username));
    }

    void setAdmin() {
        admin = true;
    }

    bool isAdmin() const {
        return admin;
    }

    bool authorize(const char* username, const char* password) {
        return (!strcmp(this->username, username) && !strcmp(this->password, password));
    }

    void read(std::ifstream& fin) const {
        fin.read((char*)this, sizeof(*this));
    }

    void write(std::ofstream& fout) const {
        fout.write((char*)this, sizeof(*this));
    }

    friend std::istream& operator>>(std::istream&, User&);
    friend std::ostream& operator<<(std::ostream&, const User&);
};

std::istream& operator>>(std::istream& is, User& object) {
    is >> object.username >> object.password >> object.admin;

    return is;
}

std::ostream& operator<<(std::ostream& os, const User& object) {
    os << object.username << " " << object.password << " " << object.admin;

    return os;
}


#endif // __USER__