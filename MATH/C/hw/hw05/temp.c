#include <stdio.h>

int main ()
{
	int a = 15,
	    b = 16;
	int *ptr_a = &a,
	    *ptr_b = &b;
	
	printf ("%d X %d = %d\n", *ptr_a, *ptr_b, (*ptr_a)*(*ptr_b));
	
	return 0;
}
