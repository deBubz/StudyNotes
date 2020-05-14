#include <iostream>

int main() {
    try
    {
        int c = 3;
        // std::cin >> c;
        bool b  = true;

        throw b;
    }
    catch(int i)
    {
        std::cout << i << std::endl;
    }
    catch(bool b)
    {
        std::cerr << b << std::endl;
    }
    
}

// cplusplus doc tutorial exceptions