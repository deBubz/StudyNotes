class Polygon 
{
    protected:
        int width;
        int height;
    public:
        Polygon (int w, int h) {
            this->width = w;
            this->height = h;
        }

        virtual int get_area() = 0;
        // declare virtual func by adding = 0
        // implemented outside
        void print_area();
};