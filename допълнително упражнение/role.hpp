#ifndef __ROLE__
#define __ROLE__
#include <stdexcept>

const short int ALIVE = 1;
const short int DYING = 0;
const short int DEAD = -1;

const bool GOOD = true;
const bool BAD = false;

class Role {
    bool alliance;
    short int status;

    void set_status(const int);

public:
    Role(const bool alliance): alliance(alliance), status(ALIVE) {}
    virtual ~Role() {}

    virtual void play(Role*) const = 0;

    bool is_good() const { return alliance; }
    bool is_alive() const { return (status != DEAD); }
    bool dying() const { return (status == DYING); } 

    void heal() { set_status(ALIVE); }
    void injure() { set_status(DYING); }
    void kill() { set_status(DEAD); }

    virtual Role* clone() const = 0;
};

void Role::set_status(const int new_status) {
    if (new_status < -1 || new_status > 1) throw std::logic_error("Invalid status value");
    status = new_status;
}


#endif // __ROLE__
