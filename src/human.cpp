#include <stdlib.h>
#include "human.h"
#include "clock.h"
#include "genotype.h"

constexpr size_t zero   =   0;

Human::Human(const Human& A, const Human& B) {
    (rand() % 2 == 0) ?
    this->sex = 'M' : this->sex = 'F';
    this->age = 0;

    Genotype *temp_gen = new Genotype(A.gens, B.gens);
    for (size_t i = 0; i < gen_len; ++i) {
        this->gens.eye_allels[i] = temp_gen->eye_allels[i];
        this->gens.hair_allels[i] = temp_gen->hair_allels[i];
        this->gens.tounge_roll_allels[i] = temp_gen->tounge_roll_allels[i];
    } 
}

Human::Human(const char& s, const Clock& a, const Genotype& g) {
    this->sex   =   s;
    this->age   =   a;
    this->gens  =   g;
}

Human::~Human() {}

Human& Human::operator =   (const Human& other) {
    this->sex   =   other.sex;
    this->age   =   other.age;
    this->gens  =   other.gens;
    return *this;
}
 
bool Human::operator   ==  (const Human& other) const {
    return this->age == other.age;
}
bool Human::operator   !=  (const Human& other) const {
    return !(*this == other);
}
bool Human::operator   >   (const Human& other) const {
    return this->age > other.age;
}
bool Human::operator   <   (const Human& other) const {
    return this->age < other.age;
}
bool Human::operator   >=  (const Human& other) const {
    return !(*this < other);
}
bool Human::operator   <=  (const Human& other) const {
    return !(*this > other);
}
char* Human::gen_data() const{
    char* output = new char[3];
    (this->gens.hair_allels[0] == 'D' || 
    this->gens.hair_allels[1] == 'D') ?
    output[0] = 'D' : output[0] = 'L';

    if (this->gens.eye_allels[0] == 'B' ||
        this->gens.eye_allels[1] == 'B')
        output[1] = 'B';
    else if (this->gens.eye_allels[0] == 'G' ||
             this->gens.eye_allels[1] == 'G')
        output[1] = 'G';
    else
        output[1] = 'S';        

    (this->gens.tounge_roll_allels[0] == 'Y' || 
    this->gens.tounge_roll_allels[1] == 'Y') ?
    output[2] = 'Y' : output[2] = 'N';

    return output;
}
