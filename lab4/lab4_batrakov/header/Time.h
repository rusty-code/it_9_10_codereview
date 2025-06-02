#ifndef TIME
#define TIME

#include "includes.h"


class Time
{
private:
    unsigned int* hours;
    unsigned int* minutes;

public:
    // Constructors
    Time(unsigned int, unsigned int);
    Time(unsigned int);
    Time();    
    // Destructors
    ~Time();

public:
    // Getters
    unsigned int get_hours();
    unsigned int get_minutes();

    // Setters
    void set_hours(unsigned int);
    void set_minutes(unsigned int);

    // Ops
    Time operator+(unsigned int);
    Time operator-(unsigned int);

    Time operator+(Time);
    Time operator-(Time);
    
    Time& operator++();
    Time& operator--();

    operator short() const;
    operator bool() const;

    friend std::ostream& operator<<(std::ostream& , const Time&);
};



#endif