#include <iostream>
#include "clock.h"

constexpr size_t zero = 0;
constexpr size_t months_num = 12;

Time::Time(size_t m = zero, size_t y = zero) {
    this->year = y + (m / months_num);
    this->month = m % months_num;
}

Time::~Time() {
    year = month = zero;
}

Time& Time::operator=(const Time &other) {
    if (this == &other)
        return *this;

    this->year = other.year;
    this->month = other.month;

    return *this;
}

bool Time::operator==(const Time &other) {
    return this->year == other.year && this->month == other.month;
}

bool Time::operator>(const Time &other) {
    if (this->year == other.year)
        return this->month > other.month;
    return this->year > other.year;
}

bool Time::operator<(const Time &other) {
    if (this->year == other.year)
        return this->month < other.month;
    return this->year < other.year;
}

bool Time::operator>=(const Time &other) {
    return !(*this < other);
}

bool Time::operator<=(const Time &other) {
    return !(*this > other);
}

void Time::next_month() {
    ++(this->month);
    if (this->month == months_num)
        this->month = zero, ++(this->year);
}

void Time::print() {
    std::cout << "Year  : " << this->year << '\n';
    std::cout << "Month : " << this->month << '\n';
}