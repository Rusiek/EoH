#include <iostream>
#include "clock.h"

constexpr size_t zero           =   0;
constexpr size_t months_num     =   12;

/**
 * @brief       
 * Construct a new Clock::Clock object
 * The purpose of struct Clock is to measure the time 
 * since a certain event with the precision of a month
 * 
 * @param m     
 * number of months    -> equal 0 if value is not given
 * 
 * @param y     
 * number of years     -> equal 0 if value is not given
 */
Clock::Clock(const size_t m, const size_t y) {
    this->year      =   y + (m / months_num);
    this->month     =   m % months_num;
}

/**
 * @brief 
 * Destroy the Clock::Clock object
 * Actually does nothing
 */
Clock::~Clock() {}

/**
 * @brief 
 * Assigment operator
 * 
 * @param other && @return Clock&
 * Clock& = other
 */
Clock& Clock::operator=(const Clock& other) {
    if (this == &other)
        return *this;

    this->year      =   other.year;
    this->month     =   other.month;

    return *this;
}

/**
 * @brief 
 * Assigment operator
 * 
 * @param other && @return Clock& 
 * Sets clock at "other" years
 */
Clock& Clock::operator=(const size_t& other) {
    this->year = other;
    this->month = zero;
    return *this;
}

/**
 * @brief 
 * Comparison operator
 * Returns true if both clocks run 
 * for the same amount of time
 * 
 * if *this == other:   @return true 
 * else:                @return false 
 */
bool Clock::operator==(const Clock& other) const{
    return (this->year == other.year && 
            this->month == other.month);
}

/**
 * @brief 
 * Comparison operator
 * Returns true if both clocks run 
 * for the different amount of time
 * 
 * if *this != other:   @return true 
 * else:                @return false 
 */
bool Clock::operator!=(const Clock& other) const{
    return !(*this == other);
}

/**
 * @brief 
 * Comparison operator
 * Returns true if "*this" clock runs 
 * longer than "other" clock
 * 
 * if *this > other:    @return true 
 * else:                @return false 
 */
bool Clock::operator>(const Clock& other) const{
    if (this->year == other.year)
        return this->month > other.month;
    return this->year > other.year;
}

/**
 * @brief 
 * Comparison operator
 * Returns true if "*this" clock runs 
 * less than "other" clock
 * 
 * if *this < other:    @return true 
 * else:                @return false 
 */
bool Clock::operator<(const Clock& other) const{
    if (this->year == other.year)
        return this->month < other.month;
    return this->year < other.year;
}

/**
 * @brief 
 * Comparison operator
 * Returns true if "*this" clock runs 
 * no less than "other" clock
 * 
 * if *this >= other:   @return true 
 * else:                @return false 
 */
bool Clock::operator>=(const Clock& other) const{
    return !(*this < other);
}

/**
 * @brief 
 * Comparison operator
 * Returns true if "*this" clock runs 
 * no longer than "other" clock
 * 
 * if *this <= other:   @return true 
 * else:                @return false 
 */
bool Clock::operator<=(const Clock& other) const{
    return !(*this > other);
}

/**
 * @brief 
 * Increases the clock value by one month 
 */
void Clock::next_month() {
    ++(this->month);
    if (this->month == months_num)
        this->month = zero, ++(this->year);
}

/**
 * @brief 
 * Prints the clock values in above format 
 * (with an endline in the end):
 * Year  : "value"
 * Month : "value"
 */
void Clock::print() const{
    std::cout << "Year  : " << this->year << '\n';
    std::cout << "Month : " << this->month << '\n';
}

/**
 * @brief && @return size_t
 * Returns number of months that have passed 
 * since last mesured year
 */
size_t Clock::get_month() const {
    return this->month;
}

/**
 * @brief && @return size_t
 * Returns number of years that have passed 
 * since the clock started
 */
size_t Clock::get_year() const {
    return this->year;
}