#ifndef __DB__
#define __DB__
#include "user.hpp"
#include "item.hpp"
#include <string>

class DB {
    std::string filename;
    User* users;
    int user_count;
    Item* items;
    int item_count;
    User* logged;

    void add_user(const User& user) {
        User *tmp = new User[user_count + 1];

        for(int i = 0; i < user_count; i++) {
            tmp[i] = users[i];
        }
        tmp[user_count] = user;

        if(users) delete[] users;
        users = tmp;
        user_count++;
    }

    void copy(const DB& other) {
        this->filename = other.filename;
        this->user_count = other.user_count;
        this->users = new User[user_count];
        this->item_count = other.item_count;
        this->items = new Item[item_count];
    
        for(int i = 0; i < user_count; i++) {
            this->users[i] = other.users[i];
        }

        for(int i = 0; i < item_count; i++) {
            this->items[i] = other.items[i];
        }

        this->logged = nullptr;
    }

    void save() const {
        std::ofstream fout(this->filename, std::ios::binary);

        fout.write((char*)&user_count, sizeof(user_count));
        for(int i = 0; i < user_count; i++) {
            users[i].write(fout);
        }

        fout.write((char*)&item_count, sizeof(item_count));
        for(int i = 0; i < item_count; i++) {
            items[i].write(fout);
        }

        fout.close();
    }

    bool authorize(const bool admin = false) const {
        if (!logged) return false;
        return admin ? logged->isAdmin() : true; 
    }

    int find_user(const char* username) const {
        User to_be_found(username);
        
        for (int i = 0; i < user_count; i++) {
            if (users[i] == to_be_found) return i;
        }

        return -1;
    }

    int find_item(const char* barcode) const {
        Item to_be_found(barcode);
        
        for (int i = 0; i < item_count; i++) {
            if (items[i] == to_be_found) return i;
        }

        return -1;
    }

public:
    DB(const std::string& filename, const char* admin_username, const char* admin_password):
user_count(0), users(nullptr), item_count(0), items(nullptr), logged(nullptr), filename(filename) {
        User admin(admin_username, admin_password);
        admin.setAdmin();
        add_user(admin);
    }

    DB(const std::string& filename) {
        this->filename = filename;
        std::ifstream fin(filename);
        fin.read((char*)&user_count, sizeof(user_count));

        users = new User[user_count];
        for(int i = 0; i < user_count; i++) {
            users[i].read(fin);
        }

        fin.read((char*)&item_count, sizeof(item_count));

        items = new Item[item_count];
        for(int i = 0; i < item_count; i++) {
            items[i].read(fin);
        }

        fin.close();
    }


    DB(const DB& other) {
        copy(other);
    }

    DB& operator=(const DB& other) {
        if (this != &other) {
            delete[] users;
            copy(other);
        }

        return *this;
    }

    ~DB() {
        save();
        delete[] users;
    }

    void login(const char* username, const char* password) {
        if (logged) throw std::runtime_error("There is already logged user!");
        int index = find_user(username);
        if (index == -1) throw std::runtime_error("There is no such user!");
        if (!users[index].authorize(username, password)) throw std::runtime_error("Wrong password!");
        logged = &users[index];
    }

    void logout() {
        if (!logged) throw std::runtime_error("There is no logged user!");
        logged = nullptr;
    }

    void register_user(const char* username, const char* password) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");
        if (find_user(username) != -1) throw std::runtime_error("This user already exists!");

        User u(username, password);
        add_user(u);
    }

    void setAdmin(const char* username) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");
        int index = find_user(username);
        if (index == -1) throw std::runtime_error("There is no such user!");
        users[index].setAdmin();
    }

    void remove_user(const char* username) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");
        int index = find_user(username);
        if (index == -1) throw std::runtime_error("There is no such user!");
        if (users[index] == *logged) throw std::runtime_error("The logged user should not be deleted!");

        User *tmp = new User[user_count - 1];
        int k = 0;
        for(int i = 0; i < index; i++, k++) {
            tmp[k] = users[i];
        }

        for (int i = index + 1; i < user_count; i++, k++) {
            tmp[k] = users[i];
        }

        delete[] users;
        users = tmp;
        user_count--;
    }

    int check_stock(const char* barcode) const {
        if (!authorize()) throw std::runtime_error("There is no logged user!");
        int index = find_item(barcode);
        if (index == -1) throw std::runtime_error("There is no such item!");

        return items[index].get_count();
    }

    void add_to_stock(const char* barcode, const int amount) {
        if (!authorize()) throw std::runtime_error("There is no logged user!");
        int index = find_item(barcode);
        if (index == -1) throw std::runtime_error("There is no such item!");

        items[index].add(amount);
    }

    void remove_to_stock(const char* barcode, const int amount) {
        if (!authorize()) throw std::runtime_error("There is no logged user!");
        int index = find_item(barcode);
        if (index == -1) throw std::runtime_error("There is no such item!");

        items[index].extract(amount);
    }

    void change_price(const char* barcode, const double price) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");
        int index = find_item(barcode);
        if (index == -1) throw std::runtime_error("There is no such item!");

        items[index].change_price(price);
    }

    void add_item(const char* barcode, const char* type, const double price) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");

        Item new_item(barcode, type, price);

        Item *tmp = new Item[item_count + 1];

        for(int i = 0; i < item_count; i++) {
            tmp[i] = items[i];
        }
        tmp[item_count] = new_item;

        if(items) delete[] items;
        items = tmp;
        item_count++;
    }

    void remove_item(const char* barcode) {
        if (!authorize(true)) throw std::runtime_error("This should be done by admin");
        int index = find_item(barcode);
        if (index == -1) throw std::runtime_error("There is no such item!");
        
        Item *tmp = new Item[item_count - 1];
        int k = 0;
        for(int i = 0; i < index; i++, k++) {
            tmp[k] = items[i];
        }

        for (int i = index + 1; i < item_count; i++, k++) {
            tmp[k] = items[i];
        }

        delete[] items;
        items = tmp;
        item_count--;
    }
};


#endif // __DB__