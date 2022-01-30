#ifndef HUMAN_H
#define HUMAN_H

struct Human{
    char sex;
    int age;

    Human(bool&);
    bool die(const int&, int);
};

Human::Human(bool& input) {
    age = 0;
    (input) ? sex = 'M' : sex = 'W';
}

bool Human::die(const int& prob, int rand) {
    return rand <= prob;
}

#endif