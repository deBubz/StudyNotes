#include <iostream>
#include <string>

using namespace std;

// pointers review

struct student {
    char fName[20];
    char lName[20];
    int sid;
};

student* get_info(){    // user input
    student* s = new student();

    cout << "enter student info\n";
    cout << "first name: ";
    cin >> s->fName;
    cout << "last name: ";
    cin >> s->lName;
    cout << "student id: ";
    cin >> s->sid;
   return s; 
}

void display(student* s){   // show user info
    cout << "\nDisplay student info\n" <<
        "Name: " << s->fName << " " << s->lName << "\n" <<
        "ID: " << s->sid << std::endl;
}

int main() {
    student* s = get_info();
    display(s);
}

