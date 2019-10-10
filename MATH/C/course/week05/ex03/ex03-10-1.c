#include <stdio.h>
#include <stdlib.h>
#define N 20

void draw_line (int num) {
	for (int i = 0; i < num; i++)
		printf ("*");
	printf ("\n");
}


int main ()
{
	// draw the first line	
	draw_line (N);
	
	// draw the slanted line
	for (int row = 1; row < N; row++) {
		for (int col = 0; col < N; col++ ) {
			if (N-row-1 == col){
				printf ("*\n");
				break;
			}
			else
				printf (" ");
		}
	}

	// draw the last line
	draw_line (N);
	return 0;
}
