// file input out put
#include <iostream>
#include <string>
#include <fstream>

// Handling saving to file
// and read from file

int main() {
    std::string a, b, line;
    std::fstream file;
    
    std::cout << "Whats your name" << std::endl;
    std::cin >> a >> b;
    // write to file
    file << a << '\n' << b;

    // read from file
    if (file.is_open()) {
        getline(file, line);
        std::cout << line
    }

    // not working yet
}