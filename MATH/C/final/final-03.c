#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{
	// input and sum up
	int sum = 0;
	for (int i = 1; i < argc; i++) 
		sum += atoi (argv[i]);

	// output
	for (int i = 1; i < argc; i++) {
		printf ("%d ", atoi (argv[i]));
		if (i < argc-1) 
			printf ("+ ");
		else
			printf ("= ");
	}
	printf ("%d\n", sum);

	return 0;
}
