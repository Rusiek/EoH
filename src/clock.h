#ifndef CLOCK_H
#define CLOCK_H
#define size_t unsigned long long

struct Clock{
private:
    size_t  year;
    size_t  month;

public:
    Clock(const size_t = 0, const size_t = 0);
    ~Clock();
    Clock& operator =   (const Clock&);
    Clock& operator =   (const size_t&);

    bool operator   ==  (const Clock&) const;
    bool operator   !=  (const Clock&) const;
    bool operator   >   (const Clock&) const;
    bool operator   <   (const Clock&) const;
    bool operator   >=  (const Clock&) const;
    bool operator   <=  (const Clock&) const;

    void next_month();
    void print() const;
    size_t get_year() const;
    size_t get_month() const;
};

#endif