#ifndef __JEDI__
#define __JEDI__
#include <cstring>
#include <cstdlib>                  // rand, srand
#include <ctime>
const int STRLEN = 51;
const int HEALTH = 100;
const int MIN_POWER = 10;
const int MAX_POWER = 20;

// помощна функция за случайни числа
int get_random_number(int min, int offset) {
    srand(time(0));                       // заради rand и генерирането на псевдослучайни числа
    return min + (rand() % offset);
}


class Jedi {
    char name[51];
    bool light_side;
    int health;
    int lightsaber_power;

public:
    Jedi(const char*, const bool);

    bool is_dead() const;
    bool get_side() const;
    const char* get_name() const;

    int attack() const;
    void get_damage(const int);
};


Jedi::Jedi(const char* name = "", const bool light_side = true): light_side(light_side), 
                                                                 health(HEALTH), 
                                                                 lightsaber_power(get_random_number(MIN_POWER, MAX_POWER - MIN_POWER)) {
    strcpy(this->name, name);       // не е възможно да използваме инициализиращия списък за name, понеже е низ (масив)
}

bool Jedi::is_dead() const {
    return this->health <= 0;
}

bool Jedi::get_side() const {
    return this->light_side;
}

const char* Jedi::get_name() const {
    return this->name;
}

int Jedi::attack() const {        // не е задължително да е get метод, ако друго име ни върши работа по-добре
    return this->lightsaber_power; 
}

void Jedi::get_damage(const int damage) {   // не е задължително get метод да връща стойност на поле
    this->health -= damage; 
}


#endif // __JEDI__
