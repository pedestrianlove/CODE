#include <stdio.h>

typedef struct {
	int data1;
	int data2;
	float data3;
}record;

int main ()
{
	record info;
	info.data1 = 100;
	info.data2 = 100;
	info.data3 = 234.5;
	
	// OUTPUT
	printf ("The sum is %.1f\n", info.data1 + info.data2 + info.data3);
	return 0;
}
