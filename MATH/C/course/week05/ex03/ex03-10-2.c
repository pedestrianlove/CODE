#include <stdio.h>
#include <stdlib.h>
#define N 20		// half length of the base

void draw_line (int num, char C) {
	for (int i = 0; i < num; i++)
		printf ("%c", C);
}

int main ()
{
	// draw the slanted line
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++ ) {
			if (N-row-1 == col){
				printf ("*");
				// enter "row-1" spacebars
				if (row != 0) {
					if (row != N/2)
						draw_line ((row)*2-1, ' ');
					else
						draw_line ((row)*2-1, '*');
					printf ("*\n");
					break;
				}
				else {
					printf ("\n");
					break;
				}
			}
			else
				printf (" ");
		}
	}

		


	return 0;
}
