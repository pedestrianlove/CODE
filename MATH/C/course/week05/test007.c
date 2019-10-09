#include <stdio.h>

#define DIM 5


int main ()
{
	for (int row = 0; row < DIM; row++) {
		for (int col = 0; col < DIM; col++) {
			if (row < col) 
				printf ("%3d", 1);
			else if (row > col)
				printf ("%3d", -1);
			else
				printf ("%3d", 0);
		}
		printf ("\n");
	}



	return 0;
}
