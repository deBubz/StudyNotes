#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *infp;
	char key[40];


	infp = fopen("in.list", "r");

	while(fgets(key, 40,infp) != NULL) 
	{
		printf("things %s", key);
	}

	return 0;
}

