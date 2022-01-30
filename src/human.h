#ifndef HUMAN_H
#define HUMAN_H

struct Human{
    char sex;
    int age;

    Human(bool&);
    bool die(const int&, int);
    Human& operator=(Human &other); 
};

Human::Human(bool& input) {
    age = 0;
    (input) ? sex = 'M' : sex = 'W';
}

bool Human::die(const int& prob, int rand) {
    return rand <= prob;
}

Human& Human::operator=(Human &other){
    this->sex = other.sex;
    this->age = other.age;
    return *this;
}

#endif