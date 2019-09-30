#include <stdio.h>

int main ()
{
	// Variables
	int number;

	// Input
	printf ("Please input a number.\n");
	scanf ("%d", &number);

	// Process && Output
	if (number > 0)
		printf ("This is a positive number.\n");
	else if (number == 0)
		printf ("This is a zero.\n");
	if (number < 0)
		printf ("This is a negative number.\n");

	return 0;	
}
