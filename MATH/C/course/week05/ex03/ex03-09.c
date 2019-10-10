#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define N 1000

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
	int prime_counter = 0;
	int line_counter = 1;
	printf ("\nThe primes in the assigned range are as follow:\n");
	printf ("===================================================\n");
	for (int i = 1; i <= N; i++) {
		if (line_counter %10 == 0){
			printf ("\n");
			line_counter = 1;
		}
		if (check_prime (i)) {
			printf ("%5d ", i);
			prime_counter ++;
			line_counter++;
		}
	}
	printf ("\n\nThere are totally %d primes.\n", prime_counter);
	printf ("===================================================\n");

	return 0;
}
