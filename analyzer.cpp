#include <iostream>
#include "StringData.h"
using namespace std;

int linear_search(vector<string> dataset, string thingtofind){
    int thinglocation = -1;
    for(int i = 0; i < dataset.size(); i++){
        if(dataset[i] == thingtofind){
            thinglocation = i;
            break;
        }
    }
    return thinglocation;
}

int binary_search(vector<string> dataset, string thingtofind){
    int low = 0;
    int high = dataset.size() - 1;
    while(low <= high){
        int middle = (int)((low + high)/2);
        if(dataset[middle] == thingtofind)
            return middle;
        else if(dataset[middle] > thingtofind)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int main(){
    vector<string> dataset = getStringData();
    printf("Search For \"not_here\":\n");

    //linear search
    long long starttime = systemTimeNanoseconds();
    printf("Linear Result: %lld\n", linear_search(dataset, "not_here"));
    long long endtime = systemTimeNanoseconds();
    printf("Time for Linear Search: %lld\n", ((endtime - starttime)));

    //binary search
    starttime = systemTimeNanoseconds();
    printf("Binary Result: %lld\n", binary_search(dataset, "not_here"));
    endtime = systemTimeNanoseconds();
    printf("Time for Binary Search: %lld\n", (endtime - starttime));

    // Search for "mzzzz":
    printf("\nSearch For \"mzzzz\":\n");

    // Linear Search
    starttime = systemTimeNanoseconds();
    printf("Linear Result: %lld\n", linear_search(dataset, "mzzzz"));
    endtime = systemTimeNanoseconds();
    printf("Time for Linear Search: %lld\n", (endtime - starttime));

    // Binary Search
    starttime = systemTimeNanoseconds();
    printf("Binary Result: %lld\n", binary_search(dataset, "mzzzz"));
    endtime = systemTimeNanoseconds();
    printf("Time for Binary Search: %lld\n", (endtime - starttime));


    // Search for "aaaaa":
    printf("\nSearch For \"aaaaa\":\n");

    // Linear Search
    starttime = systemTimeNanoseconds();
    printf("Linear Result: %lld\n", linear_search(dataset, "aaaaa"));
    endtime = systemTimeNanoseconds();
    printf("Time for Linear Search: %lld\n", (endtime - starttime));

    // Binary Search
    starttime = systemTimeNanoseconds();
    printf("Binary Result: %lld\n", binary_search(dataset, "aaaaa"));
    endtime = systemTimeNanoseconds();
    printf("Time for Binary Search: %lld\n", (endtime - starttime));

    return 0;
}