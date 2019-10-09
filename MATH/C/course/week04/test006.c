#include <stdio.h>
#include <stdlib.h>


int main ()
{
	// Variables
	int numbers;
	int* grade;
	int sum = 0;
	
	// Allocate the memory for array
	scanf ("%d", &numbers);
	grade =  malloc (numbers*sizeof(int));

	// Input the grade and sum up
	int i ;
	int flag = 0;
	for (i = 0; i < numbers; i++, flag++) {
		if (flag%10==0)
			printf ("\n");
		scanf ("%d", &grade[i]);
		printf ("%3d ", grade[i]);
		sum += grade[i];
	}


	// Output
	printf("\n");
	printf ("The sum is: %d\n", sum);


	free (grade);
	return 0;
}



