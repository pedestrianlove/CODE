#include <stdio.h>
#define N 5

void stars (int number) 
{
	for (int i = 0; i < number; i++)
		printf ("*");
}
void space (int number)
{
	for (int i = 0; i < number; i++)
		printf (" ");
}


int main ()
{
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			space(N-col);
			stars(2*row+1);
			printf ("\n");
		}
	}
/*
	for (int row = N; row > 0; row --) {
		for (int col = N; col > 0; col--) {
			space(col-1);
			stars(2*row+1);
			printf ("\n");
		}
	}
*/
	return 0;
}

