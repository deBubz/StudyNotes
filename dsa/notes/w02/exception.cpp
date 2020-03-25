#include <iostream>
#include <string>

using namespace std;

string add (int a, int b) {
    return (a + b) + "";
}

void display (string str) {
    cout <<  "Total is " << str << endl;
}

int main() {
    int age, years;

    cout << "enter your current age: " << endl;
    cin >> age;
    try {
        if (cin.fail()) {
            cout << "Not an int" << endl;
            return -1;
        } else if (age < 0) {
            throw(age);
        } else {
            // input is ok
        }      
    } catch (int age) {
        cout << "your age " << age << ", is not in the legal range" << endl;
        return -1;
    }

    // Another way of hadndling ex
    cout << "enter your current year: " << endl;
    cin >> years;
    try {
        if (cin.fail()) {
            cout << "Not an int" << endl;
            return -1;
        } else if (years + age < 0) {
            throw(years);
        } else {
            // input is ok
        }      
    } catch (int years) {
        cout << "your year " << years << ", is not in the legal range" << endl;
        return -1;
    }

    display(add(age, years));
}