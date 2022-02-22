#ifndef HUMAN_H
#define HUMAN_H
#include "genotype.h"
#include "clock.h"

struct Human{
    char sex;
    Clock age;
    Genotype gens;

    Human(const Human&, const Human&);
    Human(const char&, const Clock&, const Genotype&);
    ~Human();
    Human& operator =   (const Human& other);
    
    bool operator   ==  (const Human& other) const;
    bool operator   !=  (const Human& other) const;
    bool operator   >   (const Human& other) const;
    bool operator   <   (const Human& other) const;
    bool operator   >=  (const Human& other) const;
    bool operator   <=  (const Human& other) const;

    char* gen_data() const;
};

#endif