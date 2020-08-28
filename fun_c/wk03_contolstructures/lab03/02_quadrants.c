/*
enter x and y coordinates
return the location of the cordinates on a plane
*/

#include <stdio.h>

/* prototype */
int find_location(const int, const int);
void location_message(const int, const int, int*);

int main(void) {
    int x, y;

    /* input */
    printf("Enter x y coords: ");
    scanf("%d%d", &x, &y);

    /* output */
    find_location(x, y);

    return 0;
}

int find_location(const int x, const int y) {
    int repeat = 1;

    location_message(x, y, &repeat);

    /* one way of infinite input */
    if(repeat) return main();
}

void location_message(const int x, const int y, int * repeat) {
    if(x == 0 && y == 0) {
        printf("(%d, %d) is at the origin\n", x, y);
        *repeat = 0;
    }
    else if(x == 0)
        printf("(%d, %d) is on the X-axis\n", x, y);
    else if(y == 0)
        printf("(%d, %d) is on the Y-axis\n", x, y);
    else if(x > 0) { /* quadrant I, II */
        if (y > 0)
            printf("(%d, %d) is in Quadrant I\n", x, y);
        else
            printf("(%d, %d) is in Quadrant II\n", x, y);
    } else {    /* quadrant III, IV */
        if (y > 0)
            printf("(%d, %d) is in Quadrant IV\n", x, y);
        else
            printf("(%d, %d) is in Quadrant III\n", x, y);
    }
}