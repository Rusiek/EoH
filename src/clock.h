#ifndef CLOCK_H
#define CLOCK_H

struct Time{
    size_t year;
    size_t month;

    Time(size_t, size_t);
    ~Time();
    Time& operator=(const Time&);

    void next_month();

    bool operator==(const Time&);
    bool operator>(const Time&);
    bool operator<(const Time&);
    bool operator>=(const Time&);
    bool operator<=(const Time&);
};

Time::Time(size_t m = 0, size_t y = 0) {
    this->year = y;
    this->month = m;
}

Time::~Time() {
    year = month = 0;
}

Time& Time::operator=(const Time &other) {
    if (this == &other)
        return *this;

    this->year = other.year;
    this->month = other.month;

    return *this;
}

void Time::next_month() {
    ++(this->month);
    if (this->month == 12)
        this->month = 0, ++(this->year);
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

#endif