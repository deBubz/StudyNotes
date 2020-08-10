/*
thats a log as description

*/

#include <stdio.h>
#include <math.h>

#define G 9.8 /* acceleration of grav constant */

/* prototype */

double flight_time(double displacement, double vel, double angle);
double projectile_height(double vel, double angle, double time);
void get_input(const double *displacement, const double *vel, const double *angle);

/* main */
int main(void) {
    // calculates  the duration of projectle flight and the elevation when target is read
    // 3 input
    // horizontal displacement
    // magnitude of initial velocity
    // angle of elevation
    
    double displacement, velocity, angle;
    double time, pr_height;

    /* get input */
    get_input(&displacement, &velocity, &angle);

    /* computing flight time */
    time = flight_time(displacement, velocity, angle);
    /* computing height of projectile */
    pr_height = projectile_height(velocity, angle, time);

    /* displaing results */
    printf("Flight time of projectile: %.2lf sec\n", time);
    printf("The height of projectile: %.2lf meters\n", pr_height);

    return 0;
}


double flight_time(double displacement, double vel, double angle) {
    return displacement / (vel * cos(angle));
}

double projectile_height(double vel, double angle, double time) {
    return (vel * sin(angle) * time) - (0.5 * G * pow(time, 2));
}

void get_input(const double *displacement, const double *vel, const double *angle){
    printf("Hey hey we need some stuff from you.\n");

    printf("\t1. horizontal displacement (m): ");
    scanf("%lf", displacement);
    printf("\t2. magnitude of the initial velocity (m/s): ");
    scanf("%lf", vel);    
    printf("\t3. angle of elevation: ");
    scanf("%lf", angle);
}
