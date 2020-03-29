#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int sid;
    float score;
};

student* get_info() {
    student* ptr = new student();

    cout << "enter student info" << endl;
    cout << "Enter name";
    cin >> ptr->name;
    cout << "Enter student id";
    cin >> ptr->sid;
    cout << "Enter score";
    cin >> ptr->score;

    return ptr;
}

void display_info(student * ptr) {
    // prints everything
    cout << "This should work\n" <<
        ptr->name << '\n' << ptr->score << '\n' << ptr->sid << endl;
}

int main () {
    student * s_ptr = get_info();    // student pointer
    display_info(s_ptr);

    delete s_ptr;
}
