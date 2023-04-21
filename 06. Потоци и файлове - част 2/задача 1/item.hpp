#ifndef __ITEM__
#define __ITEM__
#include <cstring>
#include <iostream>
#include <fstream>

class Item {
    char barcode[50];
    char type[50];
    double price;
    int count;

    void change_amount(const int count) {
        this->count += count;

        // не може да имаме отрицателен брой
        if (this->count < 0) this->count = 0; 
    }

public:
    Item(const char* barcode = "", const char* type = "", const double price = 0, const int count = 0): 
price(0), count(count) {
        strcpy(this->barcode, barcode);
        strcpy(this->type, type);
        change_price(price);
    }

    bool operator==(const Item& other) const {
        return (!strcmp(this->barcode, other.barcode));
    }

    int get_count() const {
        return count;
    }

    void add(const int count) {
        change_amount(count);
    }

    void extract(const int count) {
        change_amount(count * -1);
    }

    void change_price (const double new_price) {
        if (new_price < 0) throw std::logic_error("Invalid price!");

        this->price = new_price;
    }

    void read(std::ifstream& fin) const {
        fin.read((char*)this, sizeof(*this));
    }

    void write(std::ofstream& fout) const {
        fout.write((char*)this, sizeof(*this));
    }

    friend std::istream& operator>>(std::istream&, Item&);
    friend std::ostream& operator<<(std::ostream&, const Item&);
};

std::istream& operator>>(std::istream& is, Item& object) {
    is >> object.barcode >> object.type >> object.price >> object.count;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Item& object) {
    os << object.barcode << " " << object.type << " " << object.price << " " << object.count;

    return os;
}


#endif // __ITEM__
