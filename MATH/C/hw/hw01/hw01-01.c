#include <stdio.h>
#include <stdlib.h>

int main ()
{
	// variables
	double input_temp, target_temp;


	// input
	printf("Please input the Celsius temperature:\n");
	scanf("%lf", &input_temp);

	// process
	target_temp = input_temp*1.8 + 32;


	// output
	printf("The corresponding Fahrenheit temperature is: %f", target_temp);

	return 0;
}
