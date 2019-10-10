#include <stdio.h>
#include <math.h>

double function_value (double X)
{
	return pow (X, 3)   -   2  *  pow (X, 2)   +   10  *  X   -   15;
}

int main ()
{
	double max = -3;
	double tmp;
	for (double x = -2.5 ; x <= 3; x+= 0.5) {
		tmp = function_value (x);
		if (max < tmp)
			max = tmp;
	}

	printf ("The max is %.3lf\n", max);
	

	return 0;
}
