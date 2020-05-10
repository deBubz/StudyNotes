#include <iostream> 
using namespace std; 

/*
The function returns:
    (1) the location of x, if it exists, in the given array;
    (2) -1 otherwise.
*/
int binarySearch_recursive(int arr[], int first, int length, int find)
{ 
    if (arr[0] == find) return first;
    else if(length != 0) {
        int half_index = length/2;
        if(find >= arr[half_index]){       // more
            int half[length - half_index];
            for (int i = 0; i < (length - half_index); i++)
                half[i] = arr[half_index + i];

            return binarySearch_recursive(half, (first + half_index), (length - half_index), find);
        }
        else {                              // less
            int half[half_index];
            for (int i = 0; i < half_index; i++) half[i] = arr[i];

            return binarySearch_recursive(half, first, half_index, find);
        }
    } else return -1;
} 


// iteration notes
// general: OK?
// larger:
//      single: ok?
//      multi-split: no
// smaller:
//      single: no
// multi-split: no


int binarySearch_iterative(int arr[], int first, int length, int find) 
{ 
    // if(arr[0] == find) return first;    // first
    int begin = 0;
    int end = length - 1;

    bool search_flag = true;
    int half_index = length/2;                          // pivot point
    int out = first;                                    // return index


    while (search_flag) {                               // searchi loop ======================================

        if(find >= arr[half_index]) {                   // larger side
            begin = half_index;
            cout << "large half " << half_index << endl;
            cout << "begin: " << begin << " end: " << end << endl;

            out ++;
            // cout << (end - begin) << endl;
            if((end - begin) == 0) {                    // one elem left
                cout << "hey last element to check" << endl;

                if (arr[out] != find) {     // not found
                    cout << "not match" << endl;
                    search_flag = false;
                    out = -1;   
                } else {
                    cout << "match" << endl;
                    search_flag = false;
                }
            }
            else {        // more than 1 in set
                cout << "This where the real bs starts" << endl;
            }
        }
        else {                                          // smaller side
            // begin (begin) end (half_index)
            cout << "small" << endl;
            if(begin == end) {
                search_flag = false;
            }
            else {
                // first += first;
                end = half_index;
            }
        }

        
    }

    return out;
} 
  
int main() 
{ 
    // int arr[] = {2, 3, 4, 10, 40}; 
    int arr[] = {1, 11,18,20};
    int x = 10;
    
    // length of arr = the total space taken / the space taken by an element
    int n = sizeof(arr) / sizeof(*arr); // length of arr
    // cout << n << endl;
    
    // cout << "Location of Element (recursive): " << binarySearch_recursive(arr, 0, n, x) << endl;
    cout << "Location of Element (iterative):\n" << binarySearch_iterative(arr, 0, n, x) << endl;
} 