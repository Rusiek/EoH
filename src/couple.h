#ifndef COUPLE_H
#define COUPLE_H
#include "human.h"

struct Couple{
    Human husband;
    Human wife;

    Couple(Human&, Human&);
};

Couple::Couple(Human& A, Human& B) {
    if (A.sex == 'M')
        husband = A, wife = B;
    else
        husband = B, wife = A;
}

#endif