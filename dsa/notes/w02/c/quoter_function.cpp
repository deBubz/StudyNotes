#include <iostream>
#include <string>

// simple struct example using objects

using namespace std;

struct student
{
    string name;
    int sid;
    float score;
};

student get_info()
{
    student s;

    cout << "Enter student information," << endl;
    cout << "Enter your name: ";
    cin >> s.name;
    cout << "Enter student id: ";
    cin >> s.sid;
    cout << "Enter score: ";
    cin >> s.score;
    
    return s;
}

void display_info(student s)
{
    cout << "\nDisplaying student information," << endl;
    cout << "Name: " << s.name << endl;
    cout << "id: " << s.sid << endl;
    cout << "Score: " << s.score << endl;
}

int main()
{
    student s = get_info();
    display_info(s);
    return 0;
}