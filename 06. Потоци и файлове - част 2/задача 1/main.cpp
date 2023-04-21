#include <iostream>
#include <fstream>
#include "user.hpp"
#include "db.hpp"

int main() {
    DB db("test_db.db", "fjfhf", "fhjgfhgf");
    db.login("fjfhf", "fhjgfhgf");
    db.register_user("fjfh", "jfgdgs");

    return 0;
}

