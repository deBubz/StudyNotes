#include <iostream>
#include "polygon.h"

// define printArea() of polygon.h

void Polygon::printArea() {
    std::cout << "Area: " << this->getArea() << std::endl;
}

class Rectangle : public Polygon {
    public:
        Rectangle(int x, int y) : Polygon(x, y) {}

        int getArea() {
            return width*height;
        }
};

class Triangle : public Polygon {
    public:
        Triangle(int x, int y) : Polygon(x, y) {}

        int getArea() {
            return (width*height)/2;
        }
};

int main() {
    Rectangle* r = new Rectangle(2, 5);
    Triangle* t = new Triangle(2, 5);

    r->printArea();
    t->printArea();
}