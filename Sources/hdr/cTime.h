#include <iostream>

#ifndef CTIME_H
#define CTIME_H

namespace myspace
{

    struct time
    {
        short int hours, minutes;

        time() {}
        time(short int x, short int y) : hours(x), minutes(y) {}
        time operator = (const time &t1);
    };

    const bool operator < (const time &t1, const time &t2)
    {
        int ttemp1 = t1.hours * 60 + t1.minutes;
        int ttemp2 = t2.hours * 60 + t1.minutes;

        return ttemp1 < ttemp2;
    }

    const bool operator > (const time &t1, const time &t2)
    {
        int ttemp1 = t1.hours * 60 + t1.minutes;
        int ttemp2 = t2.hours * 60 + t1.minutes;

        return ttemp1 > ttemp2;
    }

    const bool operator == (const time &t1, const time &t2)
    {
        if ((t1.hours == t2.hours) && (t1.minutes == t2.minutes))
            return true;
        return false;
    }

    const bool operator != (const time &t1, const time &t2)
    {
        return !(t1 == t2);
    }

    time time::operator = (const time &t1)
    {
        if (&t1 == this)
            return *this;
        return time(this->hours = t1.hours, this->minutes = t1.minutes);
    }

}

void output(const myspace::time &t1)
{
    std::cout << t1.hours << ":" << t1.minutes;
}

#endif
