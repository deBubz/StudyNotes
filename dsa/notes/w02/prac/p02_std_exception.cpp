#include <iostream>
#include <string>

/*
    @Name: add
    @Return: int
    @Parameters: int, int
*/
int add (int age, int years) {
    return age + years;
}

/*
    @Name: display
    @Parameters: string
*/
void display(int estimated_age) {
    std::cout << "Your estimated age is: " << estimated_age 
        << std::endl;
}

int main() {
    int age, years;

    // handling exception 1
    try {
        std::cout << "Your Current Age: ";
        std::cin >> age;
        if (std::cin.fail()) {  // input failed, not an int
            std::cout << "Not an int\n";
            return -1;
        } else if(age < 0) {
            throw(age);
        }
    } catch (int age) {
        std::cout << "How are you " << age << "years old\n";
        return -1;
    }

    // handle exception 2
    try {
    std::cout << "Number of years: ";
    std::cin >> years;
    if (std::cin.fail()) {  // input failed, not an int
        std::cout << "Not an int\n";
        return -1;
    } else if(add(age, years) < 0) {
        throw(years);
    }
    } catch (int age) {
        std::cout << "Year number: " << age << " is too small\n";
        return -1;
    }

    display(add(age, years));
    return 0;
}