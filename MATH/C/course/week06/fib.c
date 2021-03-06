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
	int line= 0;
	for (int i = 1; i <= number; i++, line++) {
		if (line % 20 == 0)
			printf ("\n");
		printf ("%5d ", fib(i));
	}

	printf ("\n");
	return 0;
}
