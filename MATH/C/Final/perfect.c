#include <stdio.h>
#include <stdlib.h>

int* getDivisor (int target)
{
	// init divisor array
	int* tmp = malloc (sizeof(int) * 32);
	for (int i = 0; i < 32; i++) {
		tmp[i] = 0;
	}

	// populate array content
	int counter = 0;
	for (int i = 1; i < target; i++) {
		if (target % i == 0)
			tmp[counter++] = i;
	}

	return tmp;
}

int checkSum (int target, int* divisors) {
	int sum = 0;
	for (int i = 0; i < 32; i++) {
		sum += divisors[i];
	}

	if (sum == target)
		return 1;
	else
		return 0;
}


int main ()
{
	printf ("The perfect number ranging from 1-1000:\n");
	for (int i = 1; i <= 1000; i++) {
		int* divisors = getDivisor (i);
		if (checkSum (i, divisors) == 1) {
			printf ("%4d\n", i);
		}

		free (divisors);
		divisors = NULL;
	}
	return 0;
}
