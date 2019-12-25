#include <stdio.h>

int acker (int m, int n)
{
	if (m == 0) 
		return n+1;
	if (n == 0)
		return acker (m-1, 1);
	return acker ( m-1 ,  acker (m, n-1) );
}

int main ()
{
	int m, n;
	
	// input
	printf ("Please input m, n for Ackerman function: ");
	scanf ("%d%d", &m, &n);

	// output
	printf ("The output is: %d\n", acker (m, n));

	return 0;
}
