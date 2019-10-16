#include <stdio.h>

int fib (int number) {
	if (number == 1 || number == 2)
		return 1;
	return fib(number-1) + fib (number-2);
}



int main ()
{	
	// VARIABLES
	int number;


	// INPUT
	printf ("Please input an integer:\n");
	scanf ("%d", &number);

	// OUTPUT
	printf ("%d\n", fib(number));

	return 0;
}
