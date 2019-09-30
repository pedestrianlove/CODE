#include <stdio.h>

int main ()
{
	// Variables
	int number;
	
	
	// Input
	printf ("Please input a positive number:\n");
	scanf ("%d", &number);

	// Process
	if (number % 2 == 0)
		printf ("This is an even.\n");
	else
		printf ("This is not an even.\n");

	return 0;
}
