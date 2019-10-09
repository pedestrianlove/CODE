#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i;
	for (i = 0; i < 38; i++)
		printf ("%d\n", rand()%100);


	return 0;
}
