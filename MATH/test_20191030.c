#include <stdio.h>
#include <stdlib.h>

int fact (int number)
{
	if (number == 1)
		return 1;
	return number * fact (number-1);
}

int main ()
{
	// Variables
	int number;
	printf ("Please input a number:\n");
	scanf ("%d", &number);

	// Process && Output
	printf ("The proposed factorial is: %d\n", fact (number));

	return 0;
}
