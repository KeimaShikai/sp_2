#include <iostream>

#ifndef CTIME_H
#define CTIME_H


struct my_time
{
    short int hours, minutes;

    my_time() {}
    my_time(short int x, short int y) : hours(x), minutes(y) {}
};


const bool operator < (const my_time &t1, const my_time &t2)
{
    int ttemp1 = t1.hours * 60 + t1.minutes;
    int ttemp2 = t2.hours * 60 + t1.minutes;

    return ttemp1 < ttemp2;
}

const bool operator > (const my_time &t1, const my_time &t2)
{
    int ttemp1 = t1.hours * 60 + t1.minutes;
    int ttemp2 = t2.hours * 60 + t1.minutes;

    return ttemp1 > ttemp2;
}

std::ostream& operator << (std::ostream &s, const my_time &t)
{
    s << '(' << t.hours << ":" << t.minutes << ")";
    return s;
}

std::istream& operator >> (std::istream &s, my_time &t)
{
    s >> t.hours >> t.minutes;
    return s;
}

bool increase(my_time &t1, my_time &t2)
{
    return t1 > t2;
}

bool decrease(my_time &t1, my_time &t2)
{
    return t1 < t2;
}

bool less_then_noon(my_time &t1)
{
    my_time noon(12, 0);
    return t1 < noon;
}

#endif
