#include <stdio.h>

int main ()
{
	// Variables
	int number;

	// Input
	scanf ("%d", &number);

	// Process && Output
	if (number > 0)
		printf ("This is a positive number.");
	else if (number == 0)
		printf ("This is a zero.");
	if (number < 0)
		printf ("This is a negative number.");

	return 0;	
}
