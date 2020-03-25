#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int sid;
    float score;
};

void get_info(student * ptr) {
    cout << "enter student info" << endl;
    cout << "Enter name";
    cin >> ptr->name;
    cout << "Enter student id";
    cin >> ptr->sid;
    cout << "Enter score";
    cin >> ptr->score;
}

void display_info(student * ptr) {
    // prints everything
    cout << "This should work\n" <<
        ptr->name << '\n' << ptr->score << '\n' << ptr->sid << endl;
}

int main () {
    student * s_ptr = new student();    // student pointer
    get_info(s_ptr);
    display_info(s_ptr);

    delete s_ptr;
}
