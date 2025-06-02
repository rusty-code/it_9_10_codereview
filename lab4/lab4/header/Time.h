#ifndef TIME
#define TIME

#include "includes.h"


class Time
{
private:
    int64_t* hours;
    int64_t* minutes;

public:
    // Constructors
    Time(int64_t, int64_t);
    Time(int64_t);
    Time();    
    // Destructors
    ~Time();

public:
    // Getters
    int64_t get_hours();
    int64_t get_minutes();

    // Setters
    void set_hours(int64_t);
    void set_minutes(int64_t);

    // Ops
    Time operator+(int64_t);
    Time operator-(int64_t);

    Time operator+(Time);
    Time operator-(Time);
    
    Time& operator++();
    Time& operator--();

    operator short() const;
    operator bool() const;

    friend std::ostream& operator<<(std::ostream& _os, const Time& _t);
};



#endif