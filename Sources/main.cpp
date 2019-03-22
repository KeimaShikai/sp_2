#include "cTime.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

template <class T1>
void sort_decrease(T1 &sample)
{
    std::vector<my_time> temp;
    while (!sample.empty())
    {
        temp.emplace_back(sample.top());
        sample.pop();
    }
    std::sort(temp.begin(), temp.end(), decrease);
    while (!temp.empty())
    {
        sample.emplace(temp.back());
        temp.pop_back();
    }
}

template <class T1>
void sort_increase(T1 &sample)
{
    std::vector<my_time> temp;
    while (!sample.empty())
    {
        temp.emplace_back(sample.top());
        sample.pop();
    }
    std::sort(temp.begin(), temp.end(), increase);
    while (!temp.empty())
    {
        sample.emplace(temp.back());
        temp.pop_back();
    }
}

template <class T1>
void output(T1 sample)
{
    while (!sample.empty())
    {
        std::cout << sample.top() << " || ";
        sample.pop();
    }
}

int main()
{
    //1
    std::stack<my_time> sample1;
    std::ifstream is("Files/for1");
    if (!is.is_open())
    {
        std::cout << "Can't open the file!\n";
        exit(0);
    }
    else
    {
        for(my_time d; is >> d;)
            sample1.emplace(d);
    }
    is.close();
    //2
    sort_decrease(sample1);
    //3
    std::cout << "Container A: ";
    output(sample1);
    //4

    return 0;
}
