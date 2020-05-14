#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    // Declaring a vector
    vector<int> v = {1, 2, 3, 4, 5}; 

    // pushback()           add at end
    // popback()            remove at end
    // begin()              addr of first elem
    // insert(pos, elem)    insert data at the given pos
    
    v.push_back(6);             // 1 2 3 4 5 6
    v.pop_back();               // 1 2 3 4 5
    v.insert(v.begin() + 1, 8); // 1 8 2 3 4 5
    v.erase(v.begin());         // 8 2 3 4 5

    // similar to java.util.ArrayList
    
    // Option 1: A traditonal way of displaying a vector's elements
    cout << "The vector elements are(traditional): ";
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
    
	/* Option 2: Displaying vector elements using iterator */
    cout << "The vector elements are(iterator): "; 
    for (vector<int>::iterator ptr = v.begin(); ptr < v.end(); ptr++) 
        cout << *ptr << " ";
    cout << endl;
    
    /* Using iterator: Displaying vector from the 4th element */
    cout << "The vector elements are(from the 4th): "; 
    for (vector<int>::iterator ptr = v.begin()+3; ptr < v.end(); ptr++) 
        cout << *ptr << " ";
    cout << endl;
    
    cout << "Vectors Elem from the 4th ";
    for (int i = 3; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
} 