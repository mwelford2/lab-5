#include <iostream>
#include "StringData.h"

using namespace std;

unsigned long long linear_search(vector<string>& container, string element)
{
    // Iterate through data
    for (unsigned long long i = 0; i < container.size(); ++i)
    {
        string item = container[i];
        // If element equals search element, return index
        if (item == element)
        {
            return i;
        }
    }
    // Iterated through all elements
    return -1;
}

unsigned long long binary_search(vector<string>& container, string element)
{
    // Use two pointers to keep track of edges of search space
    unsigned long long left = 0;
    unsigned long long right = container.size() - 1;
    while (left <= right)
    {
        // Adjust search space based on middle element
        unsigned long long mid = left + (right - left) / 2;
        // If middle element < search element, restrict search space to upper half
        if (container[mid] < element)
        {
            left = mid + 1;
        }
        // If middle element > search element, restrict search space to lower half
        else if (container[mid] > element)
        {
            right = mid - 1;
        }
        // Middle element = search element, return middle element's index
        else
        {
            return mid;
        }
    }
    // Exhausted search space
    return -1;
}

int main() {
    // Access the dataset from the stringdata module
    cout << "Accessing the dataset..." << endl;
    vector<string>& dataset = getStringData();
    cout << "Got the dataset!" << endl;
    cout << "----------------" << endl;
    
    // Search for "not_here", logging time
    cout << "Searching for \"not_here\"..." << endl;
    
    cout << "Using linear search..." << endl;
    long long begin = systemTimeNanoseconds();
    cout << "INDEX: "  << linear_search(dataset, "not_here") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
    cout << endl;
    
    cout << "Using binary search..." << endl;
    begin = systemTimeNanoseconds();
    cout << "INDEX: "  << binary_search(dataset, "not_here") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
    cout << "----------------" << endl;
    
    // Search for "mzzzz", logging time
    cout << "Searching for \"mzzzz\"..." << endl;

    cout << "Using linear search..." << endl;
    begin = systemTimeNanoseconds();
    cout << "INDEX: " << linear_search(dataset, "mzzzz") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
    cout << endl;
    
    cout << "Using binary search..." << endl;
    begin = systemTimeNanoseconds();
    cout << "INDEX: " << binary_search(dataset, "mzzzz") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
    cout << "----------------" << endl;
    
    // Search for "aaaaa", logging time
    cout << "Searching for \"aaaaa\"..." << endl;

    cout << "Using linear search..." << endl;
    begin = systemTimeNanoseconds();
    cout << "INDEX: " << linear_search(dataset, "aaaaa") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
    cout << endl;
    
    cout << "Using binary search..." << endl;
    begin = systemTimeNanoseconds();
    cout << "INDEX: " << binary_search(dataset, "aaaaa") << endl;
    cout << "ELAPSED TIME: " << ((systemTimeNanoseconds() - begin)/1e9) << endl;
}