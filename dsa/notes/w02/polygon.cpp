#include <iostream>

#include "polygon.h"

using namespace std;

// define area printing
void Polygon::print_area()
{
    cout << "Area is " << this->get_area() << endl;
}

// class rectangle inheriting Polygon
class Rect: public Polygon
{
    public:
    Rect (int x, int y) : Polygon(x, y) {};
    int get_area()
    {
        return this->width * this->height;
    };
};

//class triangle inheriting Polygon
class Triangle: public Polygon
{
    public:
    Triangle (int x, int y) : Polygon(x, y) {};
    int get_area()
    {
        return (this->width * this->height)/2;
    };
};


int main() 
{
    Rect *r = new Rect(15, 25);
    Triangle *t = new Triangle(15, 25);

    r->print_area();
    t->print_area();
}