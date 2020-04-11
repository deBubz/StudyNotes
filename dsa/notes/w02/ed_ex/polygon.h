#ifndef _P04_CLASS_H_
#define _P04_CLASS_H_

// class example header file

class Polygon {
    protected:      // child class can access protected
        int width;
        int height;
    public:
        // implemented within the class
        Polygon (int w, int h) {
            this->width = w;
            this->height = h;
        }

        // must be implemented by child class
        virtual int getArea() = 0;
        // shared used by child classes
        // but it is implemented in other files (.cpp)
        void printArea();
};

#endif