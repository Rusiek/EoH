#ifndef UR_H
#define UR_H
#include <stdint.h>

struct ultra_rabit{
    bool ROTP = false;
    uint32_t age;
    char eye;

    ultra_rabit();
    ultra_rabit(ultra_rabit&, ultra_rabit&);
    ~ultra_rabit();
    ultra_rabit& operator=(const ultra_rabit&);
   
    bool operator==(const ultra_rabit&) const;
    bool operator!=(const ultra_rabit&) const;
    bool operator<(const ultra_rabit&)  const;
    bool operator<=(const ultra_rabit&) const;
    bool operator>(const ultra_rabit&)  const;
    bool operator>=(const ultra_rabit&) const;

    void display();
};

#endif