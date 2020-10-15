/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
dynamic arrays using pointers
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* array pointer length 1 */
	int* xp;
	xp = (int*) malloc(2*sizeof(int));

	if(xp==NULL)
	{
		printf("fatal memory error\n");
		return 1;
	}
	
	*xp = 10;		/* assign value to index 0 */
	*(xp+1) = 12;	/* assign value to index 1 */
	/* print fist elem and address */
	printf("%d %p\n", *xp, xp);			/* value and address of index 0 */
	printf("%d %p\n", *(xp+1), xp+1);	/* value and address of index 1 */


	free(xp);		/* de allocate memory */
	xp = NULL;
	return 0;
}
