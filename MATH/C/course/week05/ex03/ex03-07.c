#include <stdio.h>

int main ()
{
	printf ("The solutions for inequality are as follow:\n")
	for (int x = -6; x <= 6; x++) {
		for (int y = -10; y <= 10; y++) {
			if (2*x-y < 3 && x+3*y >= 1) {
				printf ("(%d, %d)\n");
			}
		}
	}


	return 0;
}
