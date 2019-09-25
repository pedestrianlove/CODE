#include <stdio.h>

int main ()
{
	// Variables
	int number;
	
	
	// Input
	printf ("Please input a positive number N:\n");
	scanf ("%d", &number);

	// Process
	if (number % 2 == 0)
		printf ("N is an even.\n");
	else
		printf ("N is not an even.\n");

	return 0;
}
