#ifndef __EXHIBITION__
#define __EXHIBITION__
#include "picture.hpp"
const int NUMBER_OF_PICTURES = 30;

class Exhibition {
    Picture pictures[NUMBER_OF_PICTURES];
    int count;
    double ticket_price;

public:
    Exhibition(const double ticket_price);
    Exhibition(const double ticket_price, const int count, const Picture* pictures);

    void add_picture(const Picture& new_picture);

    double get_value () const;
};


Exhibition::Exhibition(const double ticket_price) {
    this->ticket_price = ticket_price;
    this->count = 0;
}

Exhibition::Exhibition(const double ticket_price, const int count, const Picture* pictures) {
    this->ticket_price = ticket_price;
    this->count = count;

    for (int i = 0; i < count; i++) {
        this->pictures[i] = pictures[i];
    }
}

void Exhibition::add_picture(const Picture& new_picture) {
    if (this->count == NUMBER_OF_PICTURES) {
        throw std::logic_error("This exhibition has no more space!");
    }

    this->pictures[this->count] = new_picture;
    this->count ++;
}

double Exhibition::get_value() const {
    double pictures_value = 0;

    for (int i = 0; i < this->count; i++) {
        pictures_value += this->pictures[i].get_value();
    }

    return this->ticket_price * pictures_value;
}

#endif // __EXHIBITION__
