#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main ()
{
	srand (time (NULL));

	for (int i = 0; i < N; i++)
		printf ("%3d ", rand()%15-10);
	printf ("\n");

	return 0;
}
