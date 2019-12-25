#include <stdio.h>
#include <stdlib.h>

int fact (int num) 
{
	if (num == 1)
		return 1;
	return num  *  fact (num-1);
}

int C (int m, int n) 
{
	if (m == 0)
		return 1;
	if (n == 0 || n == m) 
		return 1;
	return fact (m)/(fact(m-n)*fact(n));
}

void draw (char tmp, int times) 
{
	for (int i = 0; i < times; i++)
		printf ("%c", tmp);
}



int main (int argc, char* argv[])
{
	// input the size
	int SIZE = atoi (argv[1]);

	for (int layer = 0; layer < SIZE; layer ++) {
		draw ('\t', SIZE-layer);
		for (int i = 0; i <= layer; i++) {
			printf ("%d", C (layer, i));
			draw ('\t', 2);
		}
		printf ("\n");
	}



	return 0;
}
