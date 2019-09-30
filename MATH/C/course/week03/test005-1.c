#include <stdio.h>

int main ()
{
	// Variables
	int number;
	
	
	// Input
	printf ("Please input a positive number:\n");
	scanf ("%d", &number);

	// Process
	printf ("This is ");
	
	if (number % 2 != 0)
		printf ("not ");
	
	printf ("an even.\n");

	return 0;
}
