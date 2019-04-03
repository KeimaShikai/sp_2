#include "cTime.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>


std::stack<my_time> input_from_file(const char *);
std::vector<my_time> convert_to_vector(std::stack<my_time>);
std::vector<my_time> convert_to_vector(std::queue<my_time>);
void sort(std::stack<my_time> &, bool);
void sort(std::queue<my_time> &, bool);
void output(std::vector<my_time>);
std::queue<my_time> search(std::stack<my_time>);
int count(std::vector<my_time>);
std::vector<my_time> merge(std::vector<my_time>, std::vector<my_time>);


int main()
{
    //1
    std::stack<my_time> sample1 = input_from_file("Files/for1");
    //2
    sort(sample1, false);
    //3
    std::cout << "Container A: ";
    output(convert_to_vector(sample1));
    //4, 5
    std::cout << "Searching... Success!\n";
    std::queue<my_time> sample2 = search(sample1);
    //6
    std::cout << "Container B: ";
    output(convert_to_vector(sample2));
    //7
    std::cout << "Sorting... Success!\n";
    sort(sample1, true);
    sort(sample2, true);
    //8
    std::cout << "Container A: ";
    output(convert_to_vector(sample1));
    std::cout << "Container B: ";
    output(convert_to_vector(sample2));
    //9
    std::vector<my_time> sample3 = merge(convert_to_vector(sample1),
                                         convert_to_vector(sample2));
    //10
    std::cout << "Container C: ";
    output(sample3);
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


std::stack<my_time> input_from_file(const char *fName)
{
    std::stack<my_time> temp;
    std::ifstream is(fName);
    if (!is.is_open())
    {
        std::cout << "Can't open the file!\n";
        exit(0);
    }
    else
    {
        for(my_time d; is >> d;)
            temp.emplace(d);
    }
    is.close();
    return temp;
}

std::vector<my_time> convert_to_vector(std::stack<my_time> s)
{
    std::vector<my_time> temp;
    while (!s.empty())
    {
        temp.emplace_back(s.top());
        s.pop();
    }
    return temp;
}

std::vector<my_time> convert_to_vector(std::queue<my_time> q)
{
    std::vector<my_time> temp;
    while (!q.empty())
    {
        temp.emplace_back(q.front());
        q.pop();
    }
    return temp;
}

void sort(std::stack<my_time> &s, bool is_increase)
{
    std::vector<my_time> temp;
    while (!s.empty())
    {
        temp.emplace_back(s.top());
        s.pop();
    }
    if (is_increase)
        std::sort(temp.begin(), temp.end(), increase);
    else
        std::sort(temp.begin(), temp.end(), decrease);
    while (!temp.empty())
    {
        s.emplace(temp.back());
        temp.pop_back();
    }
}

void sort(std::queue<my_time> &q, bool is_increase)
{
    std::vector<my_time> temp;
    while (!q.empty())
    {
        temp.emplace_back(q.front());
        q.pop();
    }
    if (is_increase)
        std::sort(temp.begin(), temp.end(), increase);
    else
        std::sort(temp.begin(), temp.end(), decrease);
    while (!temp.empty())
    {
        q.emplace(temp.back());
        temp.pop_back();
    }
}

void output(std::vector<my_time> v)
{
    for (std::vector<my_time>::iterator it = v.begin();
            it != v.end(); ++it)
        std::cout << *it << " || ";
    std::cout << std::endl;
}

std::queue<my_time> search(std::stack<my_time> s)
{
    std::vector<my_time> temp1 = convert_to_vector(s);

    std::vector<my_time> temp2(temp1.size());
    auto it = std::copy_if(temp1.begin(), temp1.end(), temp2.begin(),
                           [](my_time t){return (less_than_noon(t));});
    temp2.resize(std::distance(temp2.begin(), it));

    std::queue<my_time> q;
    while (!temp2.empty())
    {
        q.emplace(temp2.back());
        temp2.pop_back();
    }
    return q;
}

int count(std::vector<my_time> sample)
{
    return std::count_if(sample.begin(), sample.end(),
                         [](my_time t){return (less_than_noon(t));});
}

std::vector<my_time> merge(std::vector<my_time> v1, std::vector<my_time> v2)
{
    std::vector<my_time> temp;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(temp));
    return temp;
}
