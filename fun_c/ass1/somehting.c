/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: Bao Hoang
 * Student ID: 13363332
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
#define SYDNEY "SYD"

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
int add_flight(flight_t flight_list[], int flight_count);
void display_flights(flight_t flight_list[], int flight_count);
int save_to_file(void);
int load_from_file(void);

/* get function */
/* int get_flight_code(void); */
date_time_t get_date_time();
char* get_fixedlen_string(int char_len);
int get_dest_count(char citycode[], flight_t flight_list[], int flight_count);

/* print functions */
void print_flight_header();
void print_all_flight(flight_t flight_list[], int fight_count);
void print_flight_to(char citycode[], flight_t flight_list[], int flight_count);
void print_flight(flight_t flight);
void print_loc_datetime(char location[], date_time_t dt);

/* validation */
int check_flight_code();
int check_int_range(int i, int min, int max);
int check_month(int mon);
int check_day(int day);
int check_hour(int hr);
int check_min(int min);


/*******************************************************************************
 * Main function
*******************************************************************************/
int main(void){
    int choice;
    flight_t flight_list[MAX_NUM_FLIGHTS];
    int flight_count = 0;

    /* selecting choice */
    print_menu();
    scanf("%d", &choice);

    while (choice != 5) {
        if(choice == 1) {   /* add flight */
            if (flight_count == MAX_NUM_FLIGHTS) {
                printf("Cannot add more flights - memory full\n");
            } else {
                flight_count = add_flight(flight_list, flight_count);
            }
        }
        else if(choice == 2) {   /* show all flights based on destination */
            display_flights(flight_list, flight_count);
        }
        else if(choice == 3) {   /* save all flights to file */

        }
        else if(choice == 4) {   /* load the flights from the db file */
        }
        else printf("Invalid choice\n");

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

int add_flight(flight_t flight_list[], int flight_count) {
    flight_t new_flight;

    /* need validation */
    printf("Enter flight code>\n");
    scanf("%s", new_flight.flightcode);
    /* printf("flight %s", new_flight.flightcode); */

    /* get departure date */
    printf("Enter departure info for the flight leaving SYD.\n");
    new_flight.departure_dt = get_date_time();

    /* get arrival city name */
    printf("Enter arrival city code>\n");
    strcpy(new_flight.arrival_city, get_fixedlen_string(MAX_CITYCODE_LEN));
    
    /* get arrival date */
    printf("Enter arrival info.\n");
    new_flight.arrival_dt = get_date_time();

    flight_list[flight_count++] = new_flight;
    return flight_count;
}

void display_flights(flight_t flight_list[], int flight_count) {
    int citycode_len = MAX_CITYCODE_LEN + 1;
    char citycode[citycode_len];

    printf("Enter arrival city code or enter * to show all destinations>\n");
    strcpy(citycode, get_fixedlen_string(citycode_len));

    if(!strcmp(citycode, "*")) {
        if (flight_count == 0) {
            printf("No flights\n");
        } else print_all_flight(flight_list, flight_count);
    } else {
        if(get_dest_count(citycode, flight_list, flight_count) == 0) {
            printf("No flights\n");
        } else print_flight_to(citycode, flight_list, flight_count);
    }
}


int get_dest_count(char citycode[], flight_t flight_list[], int flight_count) {
    int i, count = 0;

    for (i = 0; i < flight_count; i++) {
        if(strcmp(citycode, flight_list[i].arrival_city) == 0) {
            count++;
        }
    }

    return count;
}


int save_to_file(void) { return 0; }
int load_from_file(void) { return 0; }

/* 
-------------------------------------------------------------------
    Get Functions
-------------------------------------------------------------------
*/

date_time_t get_date_time(void) {
    date_time_t dt;
    int valid = 1;

    printf("Enter month, date, hour and minute separated by spaces>\n");
    scanf("%d%d%d%d", &dt.month, &dt.day, &dt.hour, &dt.minute);

    if(!check_month(dt.month)) valid = 0;
    if(!check_day(dt.day)) valid = 0;
    if(!check_hour(dt.hour)) valid = 0;
    if(!check_min(dt.minute)) valid = 0;

    /* keep asking for date_time if current input is bad */
    if(!valid) {
        printf("Invalid input\n");
        return get_date_time();
    }

    return dt;
}

char* get_fixedlen_string(int char_len) {
    char in[char_len];
    char* string;

    scanf("%s", in);
    /* in[char_len] = '\0'; */
    /* strcpy(string, in); */
    string = &in[0];

    return string;
}

/* 
-------------------------------------------------------------------
    Print Functions
-------------------------------------------------------------------
*/

/**
 * 
 * print the header of flights listing
 */
void print_flight_header() {
    printf("Flight Origin          Destination\n");
    printf("------ --------------- ---------------\n");
}

/**
 * print all flights
 */
void print_all_flight(flight_t flight_list[], int flight_count) {
    print_flight_header();

    /* flight body */
    int i;
    for(i = 0; i < flight_count; i++) {
        print_flight(flight_list[i]);
    }
}

/**
 * print all flights to a destination
 */
void print_flight_to(char citycode[], flight_t flight_list[], int flight_count) {
    print_flight_header();

    int i;
    for(i = 0; i < flight_count; i++) {
        /* printf("%s match with %s\n", citycode, flight_list[i].arrival_city); */

        if(strcmp(citycode, flight_list[i].arrival_city) == 0) {
            /* printf("found\n"); */
            print_flight(flight_list[i]);
        }
    }
}

/**
 * print flight detail
 */
void print_flight(flight_t flight) {
    int str_len;

    /* flight code and padding */
    printf("%s", flight.flightcode);
    for(str_len = strlen(flight.flightcode); str_len < MAX_FLIGHTCODE_LEN + 1; str_len++){
        printf(" ");
    }

    /* origin */
    print_loc_datetime(SYDNEY, flight.departure_dt);
    printf(" ");
    /* destination */
    print_loc_datetime(flight.arrival_city, flight.arrival_dt);

    printf("\n");
}

/**
 * print location date time
 */
void print_loc_datetime(char location[], date_time_t dt) {
    int str_len;

    /* flight code and padding */
    printf("%s", location);
    for(str_len = strlen(location); str_len < MAX_CITYCODE_LEN + 1; str_len++){
        printf(" ");
    }
    
    /* print date */
    printf("%02d-%02d ", dt.month, dt.day);
    printf("%02d:%02d", dt.hour, dt.minute);
}

/* 
-------------------------------------------------------------------
    Validation Functions
-------------------------------------------------------------------
*/

/**
 * Check if an integer if it is between a range (inclusive)
 * 
 * @param i the value to check
 * @param min min value of the range (inclusive)
 * @param max maximum value of the range (inclusive)
 * @return 1 if the number is in range, 0 if the number is out of range
 */
int check_int_range(int i, int min, int max) {
    if(i >= min && i <= max ) {   /* valid */
        return 1;
    } else {                    /* invalid */
        return 0;
    }
}

/**
 * Check if the entered month is valid
 * Month value should be 1 - 12 (inclusive)
 * 
 * @param mon month integer value
 * @return 1 if valid, 0 if invalid
 */
int check_month(int mon) {
    return check_int_range(mon, 1, 12);
}

/**
 * Check if the entered day is valid
 * Day value should be 1 - 31 (inclusive)
 * 
 * @param day day integer value
 * @return 1 if valid, 0 if invalid
 */
int check_day(int day) {
    return check_int_range(day, 1, 31);
}

/**
 * Check if the entered hour is valid
 * hour value should be 0 - 23 (inclusive)
 * 
 * @param hr hour integer value
 * @return 1 if valid, 0 if invalid
 */
int check_hour(int hr) {
    return check_int_range(hr, 0, 23);
}

/**
 * Check if the entered minutes is valid
 * Month value should be 0 - 59 (inclusive)
 * 
 * @param min minute integer value
 * @return 1 if valid, 0 if invalid
 */
int check_min(int min) {
    return check_int_range(min, 0, 59);
}