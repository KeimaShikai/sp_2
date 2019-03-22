#include "cTime.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>


void sort_decrease(std::stack<my_time> &sample)
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

void sort_increase(std::stack<my_time> &sample)
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

void sort_increase(std::queue<my_time> &sample)
{
    std::vector<my_time> temp;
    while (!sample.empty())
    {
        temp.emplace_back(sample.front());
        sample.pop();
    }
    std::sort(temp.begin(), temp.end(), increase);
    while (!temp.empty())
    {
        sample.emplace(temp.back());
        temp.pop_back();
    }
}

void output(std::stack<my_time> sample)
{
    while (!sample.empty())
    {
        std::cout << sample.top() << " || ";
        sample.pop();
    }
    std::cout << std::endl;
}

void output(std::queue<my_time> sample)
{
    while (!sample.empty())
    {
        std::cout << sample.front() << " || ";
        sample.pop();
    }
    std::cout << std::endl;
}

std::queue<my_time> search(std::stack<my_time> sample)
{
    std::vector<my_time> temp1;
    while (!sample.empty())
    {
        temp1.emplace_back(sample.top());
        sample.pop();
    }
    std::vector<my_time> temp2(temp1.size());
    auto it = std::copy_if(temp1.begin(), temp1.end(), temp2.begin(),
                           [](my_time t){return (less_then_noon(t));});
    temp2.resize(std::distance(temp2.begin(), it));
    std::queue<my_time> qu;
    while (!temp2.empty())
    {
        qu.emplace(temp2.back());
        temp2.pop_back();
    }
    return qu;
}

int count(std::vector<my_time> sample)
{
    return std::count_if(sample.begin(), sample.end(), [](my_time t){return (less_then_noon(t));});
}

std::vector<my_time> merge(std::stack<my_time> s1, std::queue<my_time> q1)
{
    std::vector<my_time> temp;
    while (!s1.empty())
    {
        temp.emplace_back(s1.top());
        s1.pop();
    }
    while (!q1.empty())
    {
        temp.emplace_back(q1.front());
        q1.pop();
    }
    return temp;
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
    //4, 5
    std::cout << "Searching... Success!\n";
    std::queue<my_time> sample2 = search(sample1);
    //6
    std::cout << "Container B: ";
    output(sample2);
    //7
    std::cout << "Sorting... Success!\n";
    sort_increase(sample1);
    sort_increase(sample2);
    //8
    std::cout << "Container A: ";
    output(sample1);
    std::cout << "Container B: ";
    output(sample2);
    //9
    std::vector<my_time> sample3 = merge(sample1, sample2);
    //10
    std::cout << "Container C: ";
    for (std::vector<my_time>::iterator it = sample3.begin();
            it != sample3.end(); ++it)
        std::cout << *it << " || ";
    std::cout << std::endl;
    //11
    int counter = count(sample3);
    std::cout << "Items found: " << counter << ".\n";
    //12
    if (counter > 0)
        std::cout << "Item found: True\n";
    else
        std::cout << "Item found: False\n";
    return 0;
}
