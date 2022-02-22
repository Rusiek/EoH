#include <stdlib.h>
#include "genotype.h"
#include "time.h"
#include "data.h"

void set_genotype(char*, const size_t, const char*, const size_t);
void make_2_genotype(char*, const size_t, const char*, const char*);

Genotype::Genotype() {
    set_genotype(this->eye_allels, gen_len, data::eye_color, data::eye_poss);
    set_genotype(this->hair_allels, gen_len, data::hair_color, data::hair_poss);
    set_genotype(this->tounge_roll_allels, gen_len, data::tounge_roll, data::tounge_poss);
}

Genotype::Genotype(const Genotype& A, const Genotype& B) {
    make_2_genotype(this->eye_allels, gen_len, A.eye_allels, B.eye_allels);
    make_2_genotype(this->hair_allels, gen_len, A.hair_allels, B.hair_allels);
    make_2_genotype(this->tounge_roll_allels, gen_len, A.tounge_roll_allels, B.tounge_roll_allels);
}

Genotype::~Genotype() {}

Genotype& Genotype::operator=(const Genotype& other) {
    if (this == &other)
        return *this;

    for (size_t i = 0; i < gen_len; ++i) {
        this->eye_allels[i]         =   other.eye_allels[i];
        this->hair_allels[i]        =   other.hair_allels[i];
        this->tounge_roll_allels[i] =   other.tounge_roll_allels[i];
    }
    return *this;
}

void set_genotype(char* gen_tab, const size_t gen_length, const char* gen_pick, const size_t gen_poss) {
    for (size_t i = 0; i < gen_length; ++i)
        gen_tab[i] = gen_pick[rand() % gen_poss];
}

void make_2_genotype(char* tab, const size_t gen_length, const char* tab_A, const char* tab_B) {
    tab[0]  =   tab_A[rand() % gen_length];
    tab[1]  =   tab_B[rand() % gen_length];
}