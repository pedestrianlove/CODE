#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	float a, b, c, d, x1, x2;
			
	printf ("Please key in three coefficients:\n");
	scanf ("%f%f%f", &a, &b, &c);
					
	d = b*b-4*a*c;
	if (d < 0) {
		printf("No real root\n");
	} else if (d==0) {
		x1=-b/(2*a);
		x2=x1;
		printf("%f %f\n", x1, x2);
	} else if (d>0) {
		x1 = (-b + sqrt (d))/(2*a);
		x2 = (-b - sqrt (d))/(2*a);
		printf("%f %f\n", x1, x2);
	}

	return 0;
}
