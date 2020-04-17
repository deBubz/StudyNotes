#include <iostream>
#include <vector>

// think of it as ArrayList
// dont use Vectors in JAVA

int main() {
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for (int i = 0; i < v.size(); i++) 
        std::cout << v[i] << std::endl;

    std::cout << std::endl;
    
    for (int i = 0; i < v.size(); i++)
        v[i] += 5;
    
    for (int i = 0; i < v.size(); i++) 
        std::cout << v[i] << std::endl;
    
}