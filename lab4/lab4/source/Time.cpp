#include "../header/Time.h"


// Constructs

Time::Time(int64_t _hours, int64_t _minutes)
{
    this->hours = new int64_t;
    *(this->hours) = _hours + _minutes/60;

    this->minutes = new int64_t;
    *(this->minutes) = _minutes%60;
}

Time::Time(int64_t _minutes)
{
    this->hours = new int64_t;
    *(this->hours) = _minutes/60;

    this->minutes = new int64_t;
    *(this->minutes) = _minutes%60;
}

Time::Time()
{
    this->hours = new int64_t(0);
    this->minutes = new int64_t(0);
}

// Destructs

Time::~Time()
{
    delete this->hours;
    delete this->minutes;
}

// Getters

int64_t Time::get_hours()
{
    return *(this->hours);
}

int64_t Time::get_minutes()
{
    return *(this->minutes);
}


// Setters

void Time::set_hours(int64_t _h)
{
    delete this->hours;

    this->hours = new int64_t(_h);
}

void Time::set_minutes(int64_t _m)
{
    delete this->minutes;

    *(this->hours) += _m/60;

    this->minutes = new int64_t(_m%60);
}


// Ops

Time Time::operator+(int64_t _m)
{
    return Time( *(this->hours) + _m/60, *(this->minutes) + _m%60 );
}

Time Time::operator-(int64_t _m)
{
    Time tm(0, 0);

    if ( *(this->hours) > _m/60)
    {
        if ( *(this->minutes) >= _m%60 )
        {
            tm.set_minutes(*(this->minutes) - _m%60);
        }
        else if ( *(this->minutes) < _m%60 ) // + conv hour to minuts
        {
            if ( *(this->hours) >= 1 )
            {
                tm.set_minutes(60 + *(this->minutes) - _m%60) ;
                *(this->hours) -= 1; 
            }
        }
        tm.set_hours(*(this->hours) - _m/60);
    }

    return tm;
}

Time Time::operator+(Time _inst)
{
    return Time( 
        *(this->hours) + _inst.get_hours(), ///60, 
        *(this->minutes) + _inst.get_minutes());
}

Time Time::operator-(Time _inst)
{   
    Time tm(0, 0);

    if( *(this->hours)  > _inst.get_hours() ) // if value absolute bigger
    {
        if ( *(this->minutes) >= _inst.get_minutes() )
        {
            tm.set_minutes(*(this->minutes) - _inst.get_minutes());
        }
        else if ( *(this->minutes) < _inst.get_minutes() ) // + conv hour to minuts
        {
            if ( *(this->hours) >= 1 )
            {
                tm.set_minutes(60 + *(this->minutes) - _inst.get_minutes()) ;
                *(this->hours) -= 1; 
            }
        }

        tm.set_hours(*(this->hours) - _inst.get_hours());
    }
    else if ( *(this->hours) == _inst.get_hours() ) 
    {
        if ( *(this->minutes) >= _inst.get_minutes() )
        {
            tm.set_minutes(*(this->minutes) - _inst.get_minutes()) ;
        }
    }
    // if conds is false, then return Time(0, 0)

    return tm;
}


Time& Time::operator++()
{
    *(this->hours) += (*(this->minutes)+1)/60;
    *(this->minutes) = (*(this->minutes)+1)%60;

    return *this;
}

Time& Time::operator--()
{
    if ( *(this->minutes) > 0 )
        *(this->minutes) -= 1;
    else if ( *(this->minutes) == 0 )
    {
        if ( *(this->hours) >= 1 )
        {
            *(this->hours) -= 1;
            *(this->minutes) = 59;
        }
    }
    
    return *this;
}


Time::operator bool() const
{
    return ( *(this->hours) == *(this->minutes) ) ? false : true;
}

Time::operator short() const
{
    return *(this->hours);
}


std::ostream& operator<<(std::ostream& _os, const Time& _t)
{
    _os << "[Часов: " << *(_t.hours) << " " << "Минут: " << *(_t.minutes) << "]";

    return _os;
}