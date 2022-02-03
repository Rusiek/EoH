#ifndef CLOCK_H
#define CLOCK_H
#define size_t unsigned long long

struct Time{
private:
    size_t year;
    size_t month;

public:
    Time(size_t = 0, size_t = 0);
    ~Time();
    Time& operator=(const Time&);

    bool operator==(const Time&);
    bool operator>(const Time&);
    bool operator<(const Time&);
    bool operator>=(const Time&);
    bool operator<=(const Time&);

    void next_month();
    void print();
};

#endif