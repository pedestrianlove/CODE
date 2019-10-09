#include <stdio.h>

#define N 20

int main ()
{
	int zero = 0, positive = 0, negative = 0;
	int temp;
	for (int i = 0; i < N; i++) {
		scanf ("%d", &temp);
		if (temp == 0)
			zero++;
		else if (temp > 0)
			positive ++;
		else
			negative ++;
	}

	printf ("We have %d zeros,\n %d positive numbers,\n %d negative numbers\n", zero, positive, negative);

	return 0;
}
