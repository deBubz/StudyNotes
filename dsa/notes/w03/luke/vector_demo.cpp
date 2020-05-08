#include <iostream>
#include <vector>

// think of it as ArrayList
// dont use Vectors in JAVA

int main() {
    std::vector<int> v;

    // add into array
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for (int i = 0; i < v.size(); i++) 
        std::cout << v[i] << std::endl;

    std::cout << std::endl;
    
    // change values
    for (int i = 0; i < v.size(); i++)
        v[i] += 5;
    
    for (int i = 0; i < v.size(); i++) 
        std::cout << v[i] << std::endl;
    
}