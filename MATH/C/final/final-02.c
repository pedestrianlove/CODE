#include <stdio.h>
#include <stdlib.h>

// user defined const
#define SIZE 80

int main ()
{
	// variables
	char tmp;
	int* data_array = malloc (sizeof (int) * (SIZE+1));

	// input
	int pivot = 0;
	printf ("input: ");
	while (scanf ("%c", &tmp)) {
		if (tmp == '\n')
			break;
		else
			data_array[pivot++] = atoi (&tmp);
	}
	// sum up the data
	int sum = 0;
	for (int i = 0; i < pivot; i++) 
		sum += data_array[i];
	
	// output
	printf ("output: ");
	for (int i = 0; i < pivot; i++) {
		printf ("%d", data_array[i]);
		if (i < pivot-1)
			printf ("+");
		else
			printf ("=");
	}
	printf ("%d\n", sum);

	return 0;
}
