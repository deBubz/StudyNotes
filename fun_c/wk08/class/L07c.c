/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
to show:
	define a macro with parameters (looks like a function, but NOT)

*******************************************************************************/

#include <stdio.h>

#define SQUARE(n) n*n /* fix */

int main(void)
{
	int a = SQUARE(5); /* show 5-1 */
	printf("%d\n",a);
	return 0;
}
