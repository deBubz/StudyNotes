/* example type casting */


#include <stdio.h>
 
int main(void)
{
	int first, second;
	double ans;

	/* user enter 2 integers */
	printf("Enter two integers> ");
	scanf("%d%d", &first, &second);

	ans = (double)first / second;
	printf("The result is %.3lf\n", ans);

	return (0);
} 
