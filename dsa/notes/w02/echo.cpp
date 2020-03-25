// file input out put
#include <iostream>
#include <string>
#include <ofstream>
#include <ifstream>


// Read write line

using namespace std;

int main() {
    string new_line;
    string line;
    
    cout << "Whats your name" << endl;
    getline(cin, line);         // read whole line

    // write to file
    ofstream myfile("text.txt");

    // it will open the file
    if (myfile.is_open()) {
        myfile << line << endl;
        myfile.close();
    } else {
        cout << "unable to open file"; 
    }

    // read and print from file
    ifstream read_file("text.txt");
    // try reading
}