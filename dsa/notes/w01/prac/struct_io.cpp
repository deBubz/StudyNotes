#include <iostream>
#include <string>

// ----------------------------------------

struct student
{
    std::string name;
    int sid;
    float score;
};

void read_input(student *s);
void get_output(student *s);

// ----------------------------------------

int main()
{
    student *s = new student();
    read_input(s);
    get_output(s);
}

// ----------------------------------------

void read_input(student *s)
{
    std::cout << "Enter Student Info:\n";
    std::cout << "Student Name: ";
    getline(std::cin, s->name);

    std::cout << "Student Id: ";
    std::cin >> s->sid;
    
    std::cout << "Student Score: ";
    std::cin >> s->score;
}

void get_output(student *s)
{
    std::cout << "\nStudent Name: " << s->name << 
        "\nStudent Id: " << s->sid <<
        "\nStudent Score: " << s->score;
}

