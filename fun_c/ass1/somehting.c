/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: Bao Hoang
 * Student ID: 13363332
 * Date of submission: 11 - September 2020
 * 
 * Brief:
 * - This is a simple console based program to store flight information
 * for flights departuring from Sydney.
 * - The flights information includes the flight code, departure time, 
 * arrival city and arrival time.
 * - The program is also able to save information to a data file to be stored
 * 
 * Limitations:
 * - This program can only store flight departuring from Sydney
 * - This program can only store up to 5 flights listing
 * - This program cannot select which data file to load from
 * 
*******************************************************************************/

/*******************************************************************************
 * HEADER FILES 
*******************************************************************************/
#include <stdio.h>  /* printf, scanf */
#include <string.h> /* strcpy, strlen */
#include <stdlib.h>

/*******************************************************************************
 * PREPROCESSING DIRECTIVES
*******************************************************************************/
#define MAX_FLIGHTCODE_LEN 6
#define MAX_CITYCODE_LEN 3
#define MAX_NUM_FLIGHTS 5
#define DB_NAME "database"
#define SYDNEY "SYD"

/*******************************************************************************
 * STRUCTS
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
 * FUNCTION PROTOTPYPES
*******************************************************************************/

int add_flight(flight_t flight_list[], int flight_count);
void display_flights(const flight_t flight_list[], const int flight_count);
int save_to_file(const flight_t flight_list[], const int flight_count);
int read_from_file(flight_t flight_list[]);

/* get function */
date_time_t get_date_time(void);
char* get_fixedlen_string(const int char_len);
char* get_flight_code();
int get_dest_count(const char citycode[], const flight_t flight_list[], const int flight_count);

/* print functions */
void print_menu (void);
void print_flight_header(void);
void print_all_flight(const flight_t flight_list[], const int fight_count);
void print_flight_to(const char citycode[], const flight_t flight_list[], const int flight_count);
void print_flight(const flight_t flight);
void print_loc_datetime(const char location[], const date_time_t dt);
void print_with_padding(const char location[], const int padding);

/* validation */
int check_flight_code(const char str[]);
int check_upper_char(const char c);
int check_number_char(const char c);
int check_int_range(const int i, const int min, const int max);
int check_month(const int mon);
int check_day(const int day);
int check_hour(const int hr);
int check_min(const int min);


/*******************************************************************************
 * MAIN
*******************************************************************************/
int main(void){
    int choice;
    flight_t flight_list[MAX_NUM_FLIGHTS];
    int flight_count = 0;

    /* selecting choice */
    print_menu();
    scanf("%d", &choice);

    /* main program */
    while (choice != 5) {
        if(choice == 1) {   /* add flight */
            if (flight_count < MAX_NUM_FLIGHTS) {
                flight_count = add_flight(flight_list, flight_count);
            } else {        /* memory full */
                printf("Cannot add more flights - memory full\n");
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
 * FUNCTION DEFINITIONS
*******************************************************************************/

/*******************************************************************************
 * This function add a new flight of type flight_t in to the flight_list array
 * 
 * @param flight_list - the flight array to add into
 * @param flight_count - the current count of flights stored in flight_list
 * @return the updated count of flights stored in flight_list
 */
int add_flight(flight_t flight_list[], int flight_count) {
    flight_t new_flight;

    /* get flight code */
    printf("Enter flight code>\n");
    strcpy(new_flight.flightcode, get_flight_code());

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


/*******************************************************************************
 *  This function is to display flights on to the console
 *  First it will ask if the user wants to show ALL flights or only flights to
 *  a specific destination
 * 
 *  To show all flights, enter "*"
 *  To show a specific flight, enter "CITYCODE"
 * 
 *  @param flight_list - flight list array to print from
 *  @param flight_count - current count of the flights stored in flight_list
 */
void display_flights(const flight_t flight_list[], const int flight_count) {
    int citycode_len = MAX_CITYCODE_LEN + 1;
    char citycode[citycode_len];

    /* display choice */
    printf("Enter arrival city code or enter * to show all destinations>\n");
    strcpy(citycode, get_fixedlen_string(citycode_len));

    if(!strcmp(citycode, "*")) {
        if (flight_count == 0) {    /* show all flights */
            printf("No flights\n");
        } else print_all_flight(flight_list, flight_count);
    } else {    /* show flights to a specified city */
        if(get_dest_count(citycode, flight_list, flight_count) == 0) {
            printf("No flights\n");
        } else print_flight_to(citycode, flight_list, flight_count);
    }
}



/*******************************************************************************
 *  This function will save flight data as text into a file named "database"
 *  If the file does not exist, a new file will be created
 *  
 *  NOTE: Any previous existing data will be deleted
 * 
 *  @param flight_list - flight list data to save
 *  @param flight_count - current count of the flights stored in flight_list
 */
int save_to_file(const flight_t flight_list[], const int flight_count) {
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "w");

    if(fp == NULL){
        printf("Write error\n");
        return 1;
    }

    /* writing, each flight is on one line */
    int i;
    for(i = 0; i < flight_count; i++) {
        flight_t fl = flight_list[i];
        fprintf(
            fp,
            "%s %d %d %d %d %s %d %d %d %d\n",
            fl.flightcode,
            fl.departure_dt.month,
            fl.departure_dt.day,
            fl.departure_dt.hour,
            fl.departure_dt.minute,
            fl.arrival_city,
            fl.arrival_dt.month,
            fl.arrival_dt.day,
            fl.arrival_dt.hour,
            fl.arrival_dt.minute
        );
    }
    fclose(fp);

    return 0;
}

/*******************************************************************************
 *  This function will load flight data from a file named "database"
 * 
 *  @param flight_list - flight list array to load to
 *  @return the number of flights loaded from file
 *          0 - if the file does not exist or is blank
 */
int read_from_file(flight_t flight_list[]) {
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "r");

    int count = 0;
    char line[100];
    char space[] = " ";

    if(fp == NULL){ /* file does not exist */
        printf("Read error\n");
        return 0;
    }

    /* reading each line in file */
    while(fgets(line, sizeof(line), fp)) {
        
        char *ptr = strtok(line, space);
        char *array[20];
        int i = 0;

        /* string to word array */
        while(ptr != NULL) {
            array[i++] = ptr;
            ptr = strtok(NULL, space);
        }

        /* mapping string array into type flight_t */
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


/*******************************************************************************
 * GET FUNCTIONS
*******************************************************************************/


/*******************************************************************************
 *  This function is to initialise a valid struct type date_time_t
 *  
 *  While entering, date time values, if the entered values are invalid
 *  User will be asked to enter them again
 * 
 *  Valid Month     1 - 12  (Inclusive)
 *  Valid Day       1 - 31  (Inclusive)
 *  Valid Hour      0 - 23  (Inclusive)
 *  Valid Minute    0 - 59  (Inclusive)
 * 
 * @return date_time_t object with valid date time values
 */
date_time_t get_date_time(void) {
    date_time_t dt;
    int valid = 1;

    printf("Enter month, date, hour and minute separated by spaces>\n");
    scanf("%d%d%d%d", &dt.month, &dt.day, &dt.hour, &dt.minute);

    /* validatin date time input */
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

/*******************************************************************************
 *  This function returns a char pointer, which is a string of 
 *  a specific length
 *
 *  @param char_len - the length of the string
 *  @return a char pointer to a string of a specified length
 */
char* get_fixedlen_string(const int char_len) {
    char in[char_len];
    char* string;

    scanf("%s", in);
    string = &in[0];

    return string;
}

/*******************************************************************************
 *  This function returns a char pointer, which is a string of
 *  a valid FlightCode
 * 
 *  If the entered flight code is in-valid, User will be prompt to enter
 *  the flight code again
 * 
 *  Valid flight code format:
 *  char length:    3 - 6
 *  char 1 - 2:     Uppercase letter
 *  char 3 - 6:     Numbers
 * 
 *  @return a char pointer to a string of a valid FlightCode
 */
char* get_flight_code() {
    char* out;
    /* char in_str[200]; */
    char * line = malloc(100), * linep = line;

    /* scanf("%[^\n]", in_str); */
    fgets(line, 100, stdin);

    /* fgets(in_str, 100, stdin); */
    while(!check_flight_code(line)) {
        printf("Invalid input\n");
        printf("Enter flight code>\n");
        /* scanf("%[^\n]", in_str); */

        fgets(line, 100, stdin);
        /* fgets(in_str, 200, stdin); */
    }

    printf("valid: %s\n",line);
    *out = *line;
    return out;
}

/*******************************************************************************
 *  This function returns the count of flights arriving at a specific CityCode
 * 
 *  @param citycode - char array of the city code
 *  @param flight_list - flight list array to search from
 *  @param flight_count - current count of flights stored in flight_list
 *  @return the number of flights arriving at a specific CityCode
 */
int get_dest_count(const char citycode[], const flight_t flight_list[], const int flight_count) {
    int i, count = 0;

    for (i = 0; i < flight_count; i++) {
        if(strcmp(citycode, flight_list[i].arrival_city) == 0) {
            count++;
        }
    }

    return count;
}


/*******************************************************************************
 * PRINT FUNCTIONS
*******************************************************************************/

/*******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
 */
void print_menu (void) {
    printf("\n"
    "1. add a flight\n"
    "2. display all flights to a destination\n"
    "3. save the flights to the database file\n"
    "4. load the flights from the database file\n"
    "5. exit the program\n"
    "Enter choice (number between 1-5)>\n");
}

/*******************************************************************************
 *  This function prints the flight list header when listing flights
 */
void print_flight_header(void) {
    printf("Flight Origin          Destination\n");
    printf("------ --------------- ---------------\n");
}

/*******************************************************************************
 *  This function prints all flights information from Sydney stored  in 
 *  the flight list
 *  
 *  @param flight_list - flight_t array storing the list of flights
 *  @param flight_count - number of flights stored in the flight_list array
 */
void print_all_flight(const flight_t flight_list[], const int flight_count) {
    print_flight_header();

    /* flight body */
    int i;
    for(i = 0; i < flight_count; i++) {
        print_flight(flight_list[i]);
    }
}

/*******************************************************************************
 *  This function prints all flight information from Sydney to 
 *  a specific destination
 *
 *  @param citycode - char array of the destination city code
 *  @param flight_list - flight_t array storing the list of flights
 *  @param flight_count - number of flights stored in the flight_list array
 */
void print_flight_to(const char citycode[], const flight_t flight_list[], const int flight_count) {
    print_flight_header();

    /* flights to city */
    int i;
    for(i = 0; i < flight_count; i++) {
        if(strcmp(citycode, flight_list[i].arrival_city) == 0) {
            print_flight(flight_list[i]);
        }
    }
}

/*******************************************************************************
 *  This function prints the flight detail of a flight departuring from Sydney 
 *  in the format:
 *  
 *  FLCODE SYD mm-dd hh:mm ARV mm-dd hh:mm
 *  
 *  Where   FLCODE is the flight code
 *          ARV is the arrival city code
 *
 *  @param flight - type flight_t struct contaning all information of the flight 
 */
void print_flight(const flight_t flight) {
    /* flightcode */
    print_with_padding(flight.flightcode, MAX_FLIGHTCODE_LEN );
    printf(" ");

    /* origin */
    print_loc_datetime(SYDNEY, flight.departure_dt);
    printf(" ");
    /* destination */
    print_loc_datetime(flight.arrival_city, flight.arrival_dt);

    printf("\n");
}

/*******************************************************************************
 *  This function prints city code and arrival or departure date time 
 *  in the format:
 *  
 *  CIT mm-dd hh:mm
 *
 *  @param location - the char array of the location, should be under 3 chars
 *  @param dt - date time of type date_time_t
 */
void print_loc_datetime(const char location[], const date_time_t dt) {
    /* departure/arrival location */
    print_with_padding(location, MAX_CITYCODE_LEN +1);
    
    /* date time */
    printf("%02d-%02d ", dt.month, dt.day);
    printf("%02d:%02d", dt.hour, dt.minute);
}

/*******************************************************************************
 *  This function prints a string with a minimum number space padding 
 *  the right side of the spring
 *  
 *  Padding size should be larger than char count in the string
 *  If string char count is larger, there will be no padding
 *
 *  @param str - char array of the string
 *  @param padding - minimum space padding size
 */
void print_with_padding(const char str[], const int padding) {
    int i;
    printf("%s", str);
    for(i = strlen(str); i < padding; i++){
        printf(" ");
    }
}


/*******************************************************************************
 * VALIDATION FUNCTIONS
*******************************************************************************/

/*******************************************************************************
 *  This function checks and if the enered flight code is valid or not
 * 
 *  Valid flight code format:
 *  char length:    3 - 6
 *  char 1 - 2:     Uppercase letter
 *  char 3 - 6:     Numbers
 * 
 *  @param str - char array of the flight code
 *  @return 1 - valid flight code
 *          0 - invalid flight code
 */
int check_flight_code(const char str[]) {
    int i;
    int len = strlen(str);

    /* check char length between 3 - 6 */
    if(!check_int_range(len, 3, 6)) return 0;
    /* check if char 1 - 2 is upper case */
    for(i = 0; i < 2; i++) {
        if (!check_upper_char(str[i])) return 0;
    }
    /* check if char 3 -> len is number */
    for(i = 2; i < len; i++) {
        if (!check_number_char(str[i])) return 0;
    }

    return 1;
}


/*******************************************************************************
 *  This function checks the range of what a char can be
 *  This is based on how char can also be represented as an int
 *  
 *  @param c - the char to check
 *  @param min - the lower range of char value
 *  @param max - the higher range of char value
 *  @return 1 if the char is in the allocated range
 *          0 if the char is not in the allocated range
 */
int check_char_range(const char c, const char min, const char max) {
    return (c >= min && c <= max ) ? 1 : 0;
}

/*******************************************************************************
 *  This function check if the char is an uppercase letter
 *  
 *  @param c - the char to check
 *  @return 1 the char is an uppercase letter
 *          0 the char is not an uppercase letter
 */
int check_upper_char(const char c) {
    return check_char_range(c, 'A', 'Z');
}

/*******************************************************************************
 *  This function check if the char is number
 *  
 *  @param c - the char to check
 *  @return 1 the char is a number
 *          0 the char is not a number
 */
int check_number_char(const char c) {
    return check_char_range(c , '0', '9');
}

/*******************************************************************************
 * Check if an integer if it is between a range (inclusive)
 * 
 * @param i the value to check
 * @param min min value of the range (inclusive)
 * @param max maximum value of the range (inclusive)
 * @return 1 if the number is in range, 0 if the number is out of range
 */
int check_int_range(const int i, const int min, const int max) {
    return (i >= min && i <= max ) ? 1 : 0;
}

/*******************************************************************************
 * Check if the entered month is valid
 * Month value should be 1 - 12 (inclusive)
 * 
 * @param mon month integer value
 * @return 1 if valid, 0 if invalid
 */
int check_month(const int mon) {
    return check_int_range(mon, 1, 12);
}

/*******************************************************************************
 * Check if the entered day is valid
 * Day value should be 1 - 31 (inclusive)
 * 
 * @param day day integer value
 * @return 1 if valid, 0 if invalid
 */
int check_day(const int day) {
    return check_int_range(day, 1, 31);
}

/*******************************************************************************
 * Check if the entered hour is valid
 * hour value should be 0 - 23 (inclusive)
 * 
 * @param hr hour integer value
 * @return 1 if valid, 0 if invalid
 */
int check_hour(const int hr) {
    return check_int_range(hr, 0, 23);
}

/*******************************************************************************
 * Check if the entered minutes is valid
 * Month value should be 0 - 59 (inclusive)
 * 
 * @param min minute integer value
 * @return 1 if valid, 0 if invalid
 */
int check_min(const int min) {
    return check_int_range(min, 0, 59);
}