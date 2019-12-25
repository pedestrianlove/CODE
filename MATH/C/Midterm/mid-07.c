#include <stdio.h>

int main ()
{
	// variables
	int report [6][8] = {0};

	// header
	printf ("\t\t\t\tSales Report\n");
	printf ("\t\t\t\t============\n");
	
	// print out and calc
	for (int sales = 1; sales <= 4; sales++) {
		printf ("%d ", sales);
		for (int day = 0; day < 6; day ++) {
			scanf ("%d", &report[sales-1][day]);
			report [sales-1][6] += report[sales-1][day];
			printf ("\t%5d", report [sales-1][day]);
		}
		printf ("|\t%5d\n", report [sales-1][6]);
	}
	printf ("----------------------------------------------------------------------------------------------------\n");
	printf ("Total ");
	int total_sum = 0;
	for (int day = 0; day < 6; day ++) {
		int sum = 0;
		for (int sales = 0; sales < 4; sales++)
			sum += report [sales][day];
		printf ("\t%5d", sum);
		total_sum += sum;
	}
	printf ("|\t%5d\n", total_sum);

	return 0;
}
