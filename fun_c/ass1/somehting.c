/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: no
 * Student ID: 3
 * Date of submission:
 * A brief statement on what you could achieve (less than 50 words):
 * 
 * 
 * A brief statement on what you could NOT achieve (less than 50 words):
 * 
 * 
*******************************************************************************/

/*******************************************************************************
 * List header files - do NOT use any other header files. Note that stdlib.h is
 * included in case you want to use any of the functions in there. However the
 * task can be achieved with stdio.h and string.h only.
*******************************************************************************/
#include <stdio.h>  /* printf, scanf */
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
 * List preprocessing directives - you may define your own.
*******************************************************************************/
#define MAX_FLIGHTCODE_LEN 6
#define MAX_CITYCODE_LEN 3
#define MAX_NUM_FLIGHTS 5
#define DB_NAME "database"

/*******************************************************************************
 * List structs - you may define struct date_time and struct flight only. Each
 * struct definition should have only the fields mentioned in the assignment
 * description.
*******************************************************************************/
struct date_time {
    int month;
    int day;
    int hour;
    int minute;
};
typedef struct date_time date_time_t;

struct flight {
    char flightcode[MAX_FLIGHTCODE_LEN + 1];
    date_time_t departure_dt;
    char arrival_city[MAX_CITYCODE_LEN + 1];
    date_time_t arrival_dt;
};
typedef struct flight flight_t;



/*******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
*******************************************************************************/

void print_menu (void);
int add_flights(flight_t flight_list[]);
int disply_flights(void);
int save_to_file(void);
int load_from_file(void);

/* validation */
int check_int_range(int i, int min, int max);
int check_month(int mon);
int check_day(int day);
int check_hour(int hr);
int check_min(int min);


/*******************************************************************************
 * Main
*******************************************************************************/
int main(void){
    int choice;
    flight_t flight_list[MAX_NUM_FLIGHTS];

    /* selecting choice */
    print_menu();
    scanf("%d", &choice);

    while (choice != 5) {
        if(choice == 1) {   /* add flight */
            if (!add_flights(flight_list)) {
                printf("\nSomething went wrong, please contact the dev.\n");
                return 1;
            }
        } else if(choice == 2) {   /* show all flights based on destination */

        } else if(choice == 3) {   /* save all flights to file */

        } else if(choice == 4) {   /* load the flights from the db file */
        } else printf("Invalid choice\n");

        print_menu();
        scanf("%d", &choice);
    }

    return 0;
}

/*******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
 * @param void
 * @return none
*******************************************************************************/
void print_menu (void) {
    printf("\n"
    "1. add a flight\n"
    "2. display all flights to a destination\n"
    "3. save the flights to the database file\n"
    "4. load the flights from the database file\n"
    "5. exit the program\n"
    "Enter choice (number between 1-5)>\n");
}

/* 
    Main functions
*/

int add_flights(flight_t flight_list[]) {
    flight_t new_flight;
    int mon, day, hr, min;

    /* need validation */
    printf("Enter flight code>\n");
    scanf("%s", new_flight.flightcode);

    /* printf("%s", new_flight.flightcode); */

    printf("Enter departure info for the flight leaving SYD.\n");
    printf("Enter month, date, hour and minute separated by spaces>\n");
    scanf("%d%d%d%d", &mon, &day, &hr, &min);
    new_flight.arrival_dt.month = mon;
    new_flight.arrival_dt.day = day;
    new_flight.arrival_dt.hour = hr;
    new_flight.arrival_dt.minute = min;

    printf("Enter arrival city code>\n");
    scanf("%s", new_flight.arrival_city);

    printf("Enter arrival info.\n");
    printf("Enter month, date, hour and minute separated by spaces>\n");
    new_flight.departure_dt.month = mon;
    new_flight.departure_dt.day = day;
    new_flight.departure_dt.hour = hr;
    new_flight.departure_dt.minute = min;

    return 1;
}
int disply_flights(void) {}
int save_to_file(void) {}
int load_from_file(void) {}

/* 
    Validation
*/
int check_int_range(int i, int min, int max) {
    if(i < min && i > max ) {
        return 1;
    } else {
        printf("Invalid input\n");
        return 0;
    }
}
int check_month(int mon) {
    return check_int_range(mon, 0, 13);
}
int check_day(int day) {
    return check_int_range(day, 0, 32);
}
int check_hour(int hr) {
    return check_int_range(hr, 0, 25);
}
int check_min(int min) {
    return check_int_range(min, 0, 61);
}