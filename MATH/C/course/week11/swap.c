#include <stdio.h>

void swap (int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main ()
{
	// variables
	int a, b;
	printf ("Please input 2 numbers a and b:\n");
	scanf ("%d%d", &a, &b);

	// OUTPUT
	printf ("Before swap: a=%d, b=%d\n", a, b);
	swap (&a, &b);
	printf ("After swap: a=%d, b=%d\n", a, b);
	return 0;
}
