#include <fstream>
#include <iostream>
#include <string>


// file IO using docs tutorial files
// input to file
// output from file

int main() {
    // writing intofile
    std::ofstream myfile;
    myfile.open("example.txt");
    
    if ( myfile.is_open() ) {
        // this will replace file content
        myfile << "One more file\n";
        myfile << "Another Line\n";
        myfile.close();
    }
    else {
        std::cout << "somthing went wrong";
    }
    
    // reading from file
    std::string line;
    std::ifstream openfile("example.txt");
    if (openfile.is_open()) {
        while( getline(openfile, line) ) {
            std::cout << line << std::endl;
        }
        openfile.close();
    }
    else std::cout << "something went wrong";
}