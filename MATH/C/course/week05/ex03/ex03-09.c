#include <stdio.h>
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
	for (int i = 1; i <= N; i++) {
		if (check_prime (i)) {
			printf ("%5d ", i);
			prime_counter ++;
		}
	}




	return 0;
}
