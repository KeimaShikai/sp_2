#include <iostream>

#ifndef CTIME_H
#define CTIME_H


struct my_time
{
    short int hours, minutes;

    my_time() {}
    my_time(short int x, short int y) : hours(x), minutes(y) {}
    my_time operator = (const my_time &t1);
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

const bool operator == (const my_time &t1, const my_time &t2)
{
    if ((t1.hours == t2.hours) && (t1.minutes == t2.minutes))
        return true;
    return false;
}

const bool operator != (const my_time &t1, const my_time &t2)
{
    return !(t1 == t2);
}

my_time my_time::operator = (const my_time &t1)
{
    if (&t1 == this)
        return *this;
    return my_time(this->hours = t1.hours, this->minutes = t1.minutes);
}

std::ostream& operator << (std::ostream &s, const my_time &t)
{
    s << '(' << t.hours << ":" << t.minutes << ")";
    return s;
}

std::istream& operator >> (std::istream &s, my_time &t)
{
    std::cin >> t.hours >> t.minutes;
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

#endif
