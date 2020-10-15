/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
changing the size of dynamic arrays. write a program that reads ints from the
user and stores in memory as an array. program must keep collecting inputs until
it runs out of memory or the user enters 0. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int inp;			/* input value */
	int n_input = 0;	/* input count */

	/* enter the first number */
	/* while its not 0 */
	/* keep entering inputs */
	for(scanf("%d",&inp); inp!=0; scanf("%d",&inp)) {
		printf("Number entered = %d, got %d\n", n_input++, inp);
	}
	printf("Summary:\nNumber entered = %d\n", n_input);

	return 0;
}


/* could implement this infinite loop for the project */
