// program to use two algorithms to search something
// input- list number, elements, elemnt to find  
// use binary and search algorithms

#include <iostream>
using namespace std;

// linear search

int lsearch(const int arr[], int size, int val, int &compare) 
{
    // var

    compare = 0;
    
    // iterate through each element
    
    for (int i = 0; i < size; i++) 
    {
        compare++;
        if (arr[i] == val) 
        {
            return i;
        }
    }
    return 0;
}

// binary search (need to be sorted)

int bisearch(const int arr[], int size, int val, int &compare) 
{
    //vars 
    
    int low = 0;
    int high = size - 1;
    compare = 0;
    
    // split in middle, compare and continue
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        compare++;
        
        // iterate binary
        
        if (arr[mid] == val) 
        {
            return mid; // if middle, skip
        } 
        else if (arr[mid] < val) 
        {
            low = mid + 1; //go through the left side of list
        } 
        else 
        {
            high = mid - 1; //go thro right side of list
        }
    }
    return 0;
}

// main function

int main() 
{
    //initialize vars
    
    int lcomp;
    int bcomp;
    int size; 
    int tests[size];
    int val; 
    
    // get size of list 
    
    cin >> size;
    
    // get elemtns in list
    
    for (int i = 0; i < size; i++) 
    {
        cin >> tests[i]; // puts inputs in list
    }
    
    // get value to serach for

    cin >> val;
    
    // run linear search
    
    int linear = lsearch(tests, size, val, lcomp);
    
    // run binary search
    
    int binary = bisearch(tests, size, val, bcomp);
    
    // display results
    
    cout << "Searching for the value " << val << ", located near the end of the array.\n";
    cout << "The linear search made " << lcomp << " comparisons.\n";
    cout << "The binary search made " << bcomp << " comparisons.\n";
    
    return 0;
}
