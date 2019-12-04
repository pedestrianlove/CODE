#include <stdio.h>

int main ()
{
	int x, *p;
	printf ("Please keyin the value of X:\n");
	scanf ("%d", &x);
	
	// X
	printf (" x = %d\n", x);
	printf ("&x = %p\n", &x);

	// P
	p = &x;
	printf (" p = %p\n", p);
	printf ("&p = %p\n", &p);
	printf ("*p = %d\n", *p);
}
