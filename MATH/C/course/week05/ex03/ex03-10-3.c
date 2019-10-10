#include <stdio.h>
#define N 20


void draw_line (int num, char C) 
{
	for (int i = 0; i < num; i++)
		printf ("%c", C);
}
	
int main ()
{
	// draw the upper part
	for (int row = 0; row < N; row++) {
		if (row >  N/2+1) {
			break;
		}
		for (int col = 0; col < N; col++ ) {
			if (N-row-1 == col){
				printf ("*");
				// enter "row-1" spacers
				if (row != 0) {
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

	// draw the center line (almost the same as upper part)
	for (int row = N/2; row >=0; row --) {
		for (int col = 0; col < N; col++ ) {
			if (N-row-1 == col){
				printf ("*");
				// enter "row-1" spacers
				if (row != 0) {
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

