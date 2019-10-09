#include <stdio.h>

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
	for (int i = 0; i < N; i++) {
			
	}




	return 0;
}
