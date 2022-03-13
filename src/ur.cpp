#include "ur.h"
#include <iostream>
#include <stdint.h>

namespace ur {
    constexpr uint32_t MAX_AGE = 100;
    constexpr uint32_t REP_AGE = 20;
    constexpr uint32_t MID_AGE = 50;
    constexpr uint32_t EYE_NUM = 3;

    constexpr char eye[EYE_NUM] = {'B', 'G', 'S'};

    char eye_gen(ultra_rabit&, ultra_rabit&);
    char rand_eye(uint16_t, uint16_t, uint16_t);
}

ultra_rabit::ultra_rabit() {
    this->age = 25;
    this->eye = ur::eye[rand() % ur::EYE_NUM];
    this->ROTP = false;
}
ultra_rabit::ultra_rabit(ultra_rabit& A, ultra_rabit& B) {
    this->age = 0;
    this->eye = ur::eye_gen(A, B);
    this->ROTP = false;
}
ultra_rabit::~ultra_rabit() {

}
ultra_rabit& ultra_rabit::operator=(const ultra_rabit& other) {
    this->age = other.age;
    this->eye = other.eye;
    return *this;
}

bool ultra_rabit::operator==(const ultra_rabit& other) const {
    return this->age == other.age; 
}
bool ultra_rabit::operator!=(const ultra_rabit& other) const {
    return !(*this == other);
}
bool ultra_rabit::operator<(const ultra_rabit& other)  const {
    return this->age < other.age;
}
bool ultra_rabit::operator<=(const ultra_rabit& other) const {
    return !(*this < other);
}
bool ultra_rabit::operator>(const ultra_rabit& other)  const {
    return this->age > other.age;
}
bool ultra_rabit::operator>=(const ultra_rabit& other) const {
    return !(*this > other);
}

void ultra_rabit::display() {
    std::cout << this->age << " ";
    std::cout << this->eye << " ";
    std::cout << this->ROTP << "\n";
}

char ur::eye_gen(ultra_rabit& A, ultra_rabit& B) {
    switch (A.eye) {
    case 'B':
        switch (B.eye) {
            case 'B':   return ur::rand_eye(7500, 1875, 625);
            case 'G':   return ur::rand_eye(5000, 3750, 1250);
            case 'S':   return ur::rand_eye(5000, 0, 5000);
        }
    case 'G':
        switch (B.eye) {
            case 'B':   return ur::rand_eye(5000, 3750, 1250);
            case 'G':   return ur::rand_eye(2, 7499, 2499);
            case 'S':   return ur::rand_eye(0, 5000, 5000);
        }
    case 'S':
        switch (B.eye) {
            case 'B':   return ur::rand_eye(5000, 0, 5000);
            case 'G':   return ur::rand_eye(0, 5000, 5000);
            case 'S':   return ur::rand_eye(0, 10, 9900);
        }
    }
}
char ur::rand_eye(uint16_t B, uint16_t G, uint16_t S) {
    uint16_t dice = rand() % (B + G + S);
    if (dice <= B)      return 'B';
    if (dice <= B + G)  return 'G';
    else                return 'S';
}