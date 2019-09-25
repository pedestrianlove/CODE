#include <stdio.h>

int main ()
{
	// Variables
	int number;

	// Input
	printf ("Please enter a number : \n");
	scanf ("%d", &number);

	// Process && Output
	switch (number) {
		case 1 :
			printf ("SPADE\n");
			break;
		case 2 :
			printf ("HEART\n");
			break;
		case 3 :
			printf ("DIAMOND\n");
			break;
		case 4 :
			printf ("CLUB\n");
			break;
		default :
			printf ("Input ERROR!\n");
			break;
	}	

	return 0;
}
