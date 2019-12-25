#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
	// input and sum up
	int sum = 0;
	for (int i = 0; i < argc; i++) 
		sum += strtol (argv[i], );

	// output
	for (int i = 0; i < argc; i++) {
		printf ("%d ", strtol (argv[i]));
		if (i < argc-1) 
			printf ("+ ");
		else
			printf ("= ");
	}
	printf ("%d", sum);

	return 0;
}
