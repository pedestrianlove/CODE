#include <stdio.h>
#include <stdlib.h>


int main ()
{
	// Generate random integer by rand()
	int tmp;
	for (int i = 0; i < 20; i++) {
		tmp = rand () % 16 - 3;
		printf ("%d ", tmp);
	}
	printf ("\n");

	return 0;
}
