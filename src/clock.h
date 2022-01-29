#ifndef CLOCK_H
#define CLOCK_H

struct Time{
    int year;
    int month;

    Time();

    void next_month();
};

Time::Time() {
    year = 0;
    month = 0;
}

void Time::next_month() {
    ++month;
    if (month == 12)
        month = 0, ++year;
}

#endif