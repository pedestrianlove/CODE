#include <stdio.h>
#include <stdlib.h>
#define N 20		// height of the A

void draw_line (int num, char C) {
	for (int i = 0; i < num; i++)
		printf ("%c", C);
}

int main ()
{
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++ ) {
			if (N-row-1 == col){
				// print the left slanted line
				printf ("*");
				// avoid 2 stars case in the first line
				if (row != 0) {
					// see if reach the mid and draw line of stars or spacebars 
					if (row != N/2)
						draw_line ( 2*row - 1, ' ');
					else
						draw_line ( 2*row - 1, '*');
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
