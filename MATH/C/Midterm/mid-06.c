#include <stdio.h>

int fib (int number)
{
	if (number == 1 || number == 2)
		return 1;
	else
		return fib (number-1) + fib (number-2);
}


int main ()
{
	printf ("The following are the first 30 terms of Fibonacci sequence:\n");
	int flag = 0;
	for (int i = 0; i < 30; i++, flag++) {
		if (flag%10 == 0)
			printf ("\n");
		printf ("%8d", fib(i+1));
	}	
	printf ("\n");
	return 0;
}
