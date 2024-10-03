#include <iostream>
#include "StringData.h"


using namespace std;

long long linear_search(const vector<string>& vector, const char* str)
{
    for (long long i = 0; i < vector.size(); ++i)
    {
        if (vector[i] == str)
        {
            return i;
        }
    }
    return -1;
}

long long binary_search(const vector<string>& vector, const char* str)
{
    long long left = 0;
    long long right = vector.size() - 1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (vector[mid] < str)
        {
            left = mid + 1;
        }
        else if (vector[mid] > str)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<string> dataset = getStringData();


    clock_t start = clock();
    long long not_here = linear_search(dataset, "not_here");
    clock_t end = clock();
    printf("Linear search: \"not_here\" found at index %lld in %lld ns\n", not_here, end - start);

    start = clock();
    not_here = binary_search(dataset, "not_here");
    end = clock();
    printf("Binary search: \"not_here\" found at index %lld in %lld ns\n", not_here, end - start);


    start = clock();
    long long zzzzz = linear_search(dataset, "zzzzz");
    end = clock();
    printf("Linear search: \"zzzzz\" found at index %lld in %lld ns\n", zzzzz, end - start);

    start = clock();
    zzzzz = binary_search(dataset, "zzzzz");
    end = clock();
    printf("Binary search: \"zzzzz\" found at index %lld in %lld ns\n", zzzzz, end - start);


    start = clock();
    long long mzzzz = linear_search(dataset, "mzzzz");
    end = clock();
    printf("Linear search: \"mzzzz\" found at index %lld in %lld ns\n", mzzzz, end - start);

    start = clock();
    mzzzz = binary_search(dataset, "mzzzz");
    end = clock();
    printf("Binary search: \"mzzzz\" found at index %lld in %lld ns\n", mzzzz, end - start);


    start = clock();
    long long aaaaa = linear_search(dataset, "aaaaa");
    end = clock();
    printf("Linear search: \"aaaaa\" found at index %lld in %lld ns\n", aaaaa, end - start);

    start = clock();
    aaaaa = binary_search(dataset, "aaaaa");
    end = clock();
    printf("Binary search: \"aaaaa\" found at index %lld in %lld ns\n", aaaaa, end - start);
    return 0;
}
