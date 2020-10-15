/*******************************************************************************
author     : Beeshanga Abewardana Jayawickrama
date       :

description:
Introduce other preprocessor directives - #if, #ifdef, #ifndef

show difference between (build a bug to show)
	#if: preprocessing directive (before compiling), logical expression of
	     constants
	if : not preprocessing directive (always compiled), logical expression of
	     variable/constants

*******************************************************************************/

#include <stdio.h>

int main(void)
{
	int i;
	char a [] = {'a', 'b', 'c'};
	
	for (i=0; i<4; i++)
	{
		printf("%c\n", a[i]);
	}

	return 0;
}
