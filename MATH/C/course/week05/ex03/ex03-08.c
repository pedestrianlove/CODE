#include <stdio.h>
#include <math.h>

int check_prime (int number) 
{
	// exclude the even case
	if (number %2 == 0)
		return 0;

	// check for odd case
	for (int i = 3; i <= sqrt (number); i+= 2) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}

int main ()
{
	// INPUT
	int number;
	printf ("Please input a number:\n");
	scanf ("%d", &number);

	// PROCESS
	if (check_prime(number))
		printf ("This is a prime.\n");
	else
		printf ("This is not a prime.\n");

	return 0;
}
