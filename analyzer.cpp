#include <iostream>
#include "StringData.h"
using namespace std;
long long linear_search(vector<string>& container, string element)
{
    for(unsigned long long i = 0; i < container.size(); i++)
    {
        if(container[i] == element) return i;
    }
    return -1;
}

long long binary_search(vector<string>& container, string element)
{
    unsigned long long low = 0, high = container.size() - 1;
    while(low <= high)
    {
        unsigned long long mid = (low + high) / 2;
        if(container[mid] == element)
        {
            return mid;
        }
        else if (container[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<string>& dataset = getStringData();

    cout << "Search \"not_here\"..." << endl;
    cout<<"Linear Search: " << endl;
    long long begin = systemTimeNanoseconds();
    cout<<"Index: " << linear_search(dataset, "not_here")<< endl;
    cout<<"Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;
    cout<<endl;

    cout<<"Binary Search: " << endl;
    begin = systemTimeNanoseconds();
    cout<<"Index: " << binary_search(dataset, "not_here")<< endl;
    cout << "Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;

    cout << "Search \"mzzzz\"..." << endl;
    cout<<"Linear Search: " << endl;
    begin = systemTimeNanoseconds();
    cout<<"Index: " << linear_search(dataset, "mzzzz")<< endl;
    cout<<"Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;
    cout<<endl;

    cout<<"Binary Search: " << endl;
    begin = systemTimeNanoseconds();
    cout<<"Index: " << binary_search(dataset, "mzzzz")<< endl;
    cout << "Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;
    cout << endl;

    cout << "Search \"aaaaa\"..." << endl;
    cout<<"Linear Search: " << endl;
    begin = systemTimeNanoseconds();
    cout<<"Index: " << linear_search(dataset, "aaaaa")<< endl;
    cout<<"Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;
    cout<<endl;

    cout<<"Binary Search: " << endl;
    begin = systemTimeNanoseconds();
    cout<<"Index: " << binary_search(dataset, "aaaaa")<< endl;
    cout << "Time: " << ((systemTimeNanoseconds() - begin)/1e9)<<endl;
}

