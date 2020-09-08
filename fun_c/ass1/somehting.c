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
int save_to_file(flight_t flight_list[], int flight_count);
int read_from_file(flight_t flight_list[]);

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
void print_with_padding(char location[], int padding);

/* file processing */


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
            save_to_file(flight_list, flight_count);
        }
        else if(choice == 4) {   /* load the flights from the db file */
            flight_count = read_from_file(flight_list);
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

int save_to_file(flight_t flight_list[], int flight_count) {
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "w");

    if(fp == NULL){
        printf("Write error\n");
        return 1;
    }

    /* writing */
    int i;
    for(i = 0; i < flight_count; i++) {
        fprintf(
            fp,
            "%s %d %d %d %d %s %d %d %d %d\n",
            flight_list[i].flightcode,
            flight_list[i].departure_dt.month,
            flight_list[i].departure_dt.day,
            flight_list[i].departure_dt.hour,
            flight_list[i].departure_dt.minute,
            flight_list[i].arrival_city,
            flight_list[i].arrival_dt.month,
            flight_list[i].arrival_dt.day,
            flight_list[i].arrival_dt.hour,
            flight_list[i].arrival_dt.minute
        );
    }

    fclose(fp);

    return 0;
}

int read_from_file(flight_t flight_list[]) {
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "r");

    int count = 0;
    char line[100];
    char space[] = " ";

    if(fp == NULL){
        printf("Read error\n");
        return 0;
    }

    /* reading each line*/
    while(fgets(line, sizeof(line), fp)) {
        /* printf("%s\n,", line); */

        char *ptr = strtok(line, space);
        char *array[20];
        int i = 0;

        /* string to array */
        while(ptr != NULL) {
            array[i++] = ptr;
            /* printf("%s ", array[i-1]); */
            ptr = strtok(NULL, space);
        }

        flight_t flight;
        strcpy(flight.flightcode, array[0]);
        flight.departure_dt.month = atoi(array[1]);
        flight.departure_dt.day = atoi(array[2]);
        flight.departure_dt.hour = atoi(array[3]);
        flight.departure_dt.minute = atoi(array[4]);
        strcpy(flight.arrival_city, array[5]);
        flight.arrival_dt.month = atoi(array[6]);
        flight.arrival_dt.day = atoi(array[7]);
        flight.arrival_dt.hour = atoi(array[8]);
        flight.arrival_dt.minute = atoi(array[9]);

        flight_list[count++] = flight;
    }

    return count;
}


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
        if(strcmp(citycode, flight_list[i].arrival_city) == 0) {
            print_flight(flight_list[i]);
        }
    }
}

/**
 * print flight detail
 */
void print_flight(flight_t flight) {
    /* flightcode */
    print_with_padding(flight.flightcode, MAX_FLIGHTCODE_LEN + 1);

    /* origin */
    print_loc_datetime(SYDNEY, flight.departure_dt);
    printf(" ");
    /* destination */
    print_loc_datetime(flight.arrival_city, flight.arrival_dt);

    printf("\n");
}

/**
 * Prints departure/arrival location and Datetime of the flight
 * Prints in the format:
 *  LOC mn-da hr:mn
 */
void print_loc_datetime(char location[], date_time_t dt) {
    /* departure/arrival location */
    print_with_padding(location, MAX_CITYCODE_LEN +1);
    
    /* print date time */
    printf("%02d-%02d ", dt.month, dt.day);
    printf("%02d:%02d", dt.hour, dt.minute);
}

void print_with_padding(char location[], int padding) {
    int i;
    printf("%s", location);
    for(i = strlen(location); i < padding; i++){
        printf(" ");
    }
}

/* 
-------------------------------------------------------------------
    FileProcessing Functions
-------------------------------------------------------------------
*/


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
    if(i >= min && i <= max ) { /* valid */
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