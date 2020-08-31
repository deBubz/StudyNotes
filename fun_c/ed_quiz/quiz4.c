#include <stdio.h>
#include <stdlib.h>

struct ipaddr {
	int octet1;
	int octet2;
	int octet3;
	int octet4;
};
typedef struct ipaddr ipaddr_t;


void print_ipaddr(ipaddr_t ip);
int is_valid(ipaddr_t ip);

/*
Two IP addresses are equal if all 4 octets of both addresses have identical
values. The function checks if two IP addresses are equal.
Inputs:
  ip1 - ipaddr_t input IP address 1
  ip2 - ipaddr_t input IP address 2
Return:
  1 - if ip1 and ip2 are equal
  0 - otherwise
*/
int is_equal(ipaddr_t ip1, ipaddr_t ip2);

/*
Two IP addresses are said to be in the same subnet if octet1, octet2 and octet3 
have identical values. The function checks if two ip addresses are in the same
subnet.
Note for students with a networking background: we are considering a simplified
definition of a subnet. Use the above definition given for this question.
Inputs:
  ip1 - ipaddr_t input IP address 1
  ip2 - ipaddr_t input IP address 2
Return:
  1 - if ip1 and ip2 are in the same subnet
  0 - otherwise
*/
int is_same_subnet(ipaddr_t ip1, ipaddr_t ip2);

/*
The function prompts the user to enter IP addresses in the following format:
  octet1.octet2.octet3.octet4
in separate lines. If an input IP address is invalid, the function prints the
following error message:
  Invalid input
and prompt the user again to give a valid input. The function may scan up to 
addr_array_len valid IP addresses, or until the user enters -1.-1.-1.-1 as the
input, whichever occurs first.


Inputs:
  addr_array_len - maximum possible number of inputs, this is the size of the
    addr_array array.
  addr_array - valid addresses from the user are saved to this array.
Return:
  the number of valid IP addresses given by the user
Post:
  After the function has been called, addr_array contains the valid IP
  addresses entered by the user.
*/
int get_valid_ipaddrs(ipaddr_t addr_array[], int addr_array_len);

/*
Display IP addresses in the same subnet in addr_array. All addresses in the one
subnet should be displayed in the same line, in the same order the addresses
were entered. Each address is separated by one space, and each line has a
trailing space in the end of the line prior to the new line character.

Input:
  addr_array - contains IP addresses
  addr_array_len - the number of IP addresses in the addr_array
*/
void print_same_subnet(const ipaddr_t addr_array[], int addr_array_len);

void print_menu();

/* ------------------------------- */
int exit_ip_input(ipaddr_t ip);
ipaddr_t enter_ip(int i);
void print_ip_arr(const ipaddr_t addr_array[], int addr_array_len);

int main (void){
    int choice;
    print_menu();

    /* get Choice */
    printf("Enter a choice> \n");
    scanf("%d", &choice);

    /* menu choices */
    if(choice == 1) {   /* OK test 1 */
        ipaddr_t ip;

        printf("Give the octects in order seperated by spaces: \n");
        ip = enter_ip(0);
        
        printf("print_ipaddr: function prints an IP address in the specified format\n");
        print_ipaddr(ip);
        printf("\n");
    }

    if(choice == 2) {   /* 2, 3 */
        ipaddr_t ip = enter_ip(0);

        printf("Give the octects in order seperated by spaces: \n");
        printf("is_valid: function returns 1 if the ip address is valid. input: ");
        print_ipaddr(ip); printf("\n");

        printf("is_valid: %s\n", is_valid(ip)? "PASS" : "FAIL");
    }

    if(choice == 3) {   /* 4, 5 */
        ipaddr_t ip1, ip2;
        
        /* get ip1 and ip2 */
        printf("Give the octects of the first IP address in order seperated by spaces: \n");
        ip1 = enter_ip(0);
        printf("Give the octects of the second IP address in order seperated by spaces: \n");
        ip2 = enter_ip(0);

        /* ouput */
        printf("is_equal: function returns 1 if the ip addresses are equal. input: ");
        print_ipaddr(ip1);
        printf(" ");
        print_ipaddr(ip2);
        
        printf("\nis_valid: %s\n", is_equal(ip1, ip2)? "PASS" : "FAIL");
}

    if(choice == 4) { /* 6, 7 */
        ipaddr_t ip1, ip2;
        
        /* get ip1 and ip2 */
        printf("Give the octects of the first IP address in order seperated by spaces: \n");
        ip1 = enter_ip(0);
        printf("Give the octects of the second IP address in order seperated by spaces: \n");
        ip2 = enter_ip(0);

        /* ouput */
        printf("is_same_subnet: function returns 1 if the ip addresses are in the same subnet. input: ");
        print_ipaddr(ip1);
        printf(" ");
        print_ipaddr(ip2);

        printf("\nis_valid: %s\n", is_same_subnet(ip1, ip2)? "PASS" : "FAIL");
    }

    if(choice == 5) {   /* 8, 9 */
        int len, valid;

        /* array length */
        printf("Give the number of IP addresses: \n");
        scanf("%d", &len);

        /* set ip array length*/
        ipaddr_t ip_arr[len];
        printf("get_valid_ipaddrs: calling the functions with addr_array_len=%d\n", len);
        /* wierd way of setting ip array elems & valid ip count */
        valid = get_valid_ipaddrs(ip_arr, len);
        printf("get_valid_ipaddrs: returned %d\n", valid);
            
        /* output */
        printf("get_valid_ipaddrs: after calling the function, addr_array contains:\n");
        print_ip_arr(ip_arr, valid);
    }
    
    if(choice == 6) { /* 10 */
        int len, valid;

        /* array length */
        printf("Give the number of IP addresses: \n");
        scanf("%d", &len);

        /* set ip array length*/
        ipaddr_t ip_arr[len];
        printf("print_same_subnet: using get_valid_ipaddrs to fill addr_array\n");
        /* wierd way of setting ip array elems & valid ip count */
        valid = get_valid_ipaddrs(ip_arr, len);
        printf("print_same_subnet: get_valid_ipaddrs returned %d\n", valid);

        /* print all ip in arrays */
        printf("print_same_subnet: addr_array contains:\n");
        print_ip_arr(ip_arr, valid);

        /* print subnet groups */
        printf("print_same_subnet: function prints all subnets in the format\n");
        printf("specified in addr_array, with addr_array_len=%d\n", valid);
        print_same_subnet(ip_arr, valid);
}
    return 0;
}

void print_menu(){
    printf("1. Print IP \n");
    printf("2. Check if IP is valid \n");
    printf("3. Check if two IPs are equal \n");
    printf("4. Check if IPs are in same subnet \n");
    printf("5. Get valid IPs \n");
    printf("6. Print all subnets \n");
    printf("7. Exit \n");
}
/* TODO: function definition */

/**
 * This function prints a ipaddr_t variable on the terminal in the following format
 * octet1.octet2.octet3.octet4
 * No spaces, no new line in the end, octets are separated by a dot.
 * @param ip address
 */
void print_ipaddr(ipaddr_t ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

/**
 * An IP address is valid if all 4 octets have values between 0 and 255(inclusive).
 * The function checks if the input ip address is valid.
 * @param ip - ipaddr_t input IP address variable
 * @return 1 - ip is valid, 0 - otherwise
*/
int is_valid(ipaddr_t ip) {
    int valid = 1;

    if (ip.octet1 < 0 || ip.octet1 > 255) valid = 0;
    if (ip.octet2 < 0 || ip.octet2 > 255) valid = 0;
    if (ip.octet3 < 0 || ip.octet3 > 255) valid = 0;
    if (ip.octet4 < 0 || ip.octet4 > 255) valid = 0;

    return valid;
}

/* 
is 2 ip equals
*/
int is_equal(ipaddr_t ip1, ipaddr_t ip2) {
    if(ip1.octet1 != ip2.octet1) return 0;
    if(ip1.octet2 != ip2.octet2) return 0;
    if(ip1.octet3 != ip2.octet3) return 0;
    if(ip1.octet4 != ip2.octet4) return 0;

    return 1;
}

/* 
subnet thing if oct1, 2, 3 are all equals
1 - valid
0 - not subnet
*/
int is_same_subnet(ipaddr_t ip1, ipaddr_t ip2) {
    if(ip1.octet1 != ip2.octet1) return 0;
    if(ip1.octet2 != ip2.octet2) return 0;
    if(ip1.octet3 != ip2.octet3) return 0;

    return 1;
}

/* enter ip array? */
int get_valid_ipaddrs(ipaddr_t addr_array[], int addr_array_len) {
    int valid = 0;
    ipaddr_t ip;

    while(valid < addr_array_len && exit_ip_input(ip) != 1) {
        printf(">\n");
        ip = enter_ip(1);

        /* check validity */
        if(is_valid(ip)) 
            addr_array[valid++] = ip;
        else
            if(!exit_ip_input(ip))
                printf("Invalid input\n");
    }

    return valid;
}

/* 1 exit, 0 continue */
int exit_ip_input(ipaddr_t ip) {
    if(ip.octet1 == -1 && ip.octet2 == -1 && ip.octet3 == -1 && ip.octet4 == -1)
        return 1;
    return 0;
}

ipaddr_t enter_ip(int i) {
    ipaddr_t ip;

    if(i) scanf("%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);
    else scanf("%d %d %d %d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);

    return ip;
}

void print_ip_arr(const ipaddr_t addr_array[], int addr_array_len) {
    int i;

    for(i = 0; i < addr_array_len; i++) {
        print_ipaddr(addr_array[i]);
        printf("\n");
    }
}

void print_same_subnet(const ipaddr_t addr_array[], int addr_array_len) {
    int i, j;
    int read[addr_array_len];

    for(i = 0; i < addr_array_len; i++)
        read[i] = 0;

    for(i = 0; i < addr_array_len && read[i] == 0; i++) {
        /* inner */
        print_ipaddr(addr_array[i]);
        printf(" ");

        for(j = i + 1; j < addr_array_len && read[j] == 0; j++) {
            if(is_same_subnet(addr_array[i], addr_array[j])) {
                print_ipaddr(addr_array[j]);
                printf(" ");
                read[j] = 1;
            }
        }

        read[i] = 1;
        printf("\n");
    }
}
