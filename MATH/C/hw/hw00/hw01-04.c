#include <stdio.h>
#include <stdlib.h>


int main ()
{
	// variables
	int items;
	float price, unit;
	double final_price;

	// input && process
	printf ("請輸入品項的數目：\n");
	scanf ("%d", &items);
	
	
	final_price = 0;
	for (int i = 0; i < items; i++) {
		printf ("請輸入品項的價格：\n");
		scanf ("%f", &price);
		printf ("請輸入品項的數量：\n");
		scanf ("%f", &unit);
		final_price += price * unit;
	}

	// output
	printf("總計：%lf\n", final_price);



	return 0;
}

