/*
 *財產折舊的計算方法有多種，其中一種叫「定率折舊法」。
 *設 V0 為原值，年折舊率為 r 
 *則 n 年後其殘值為 Vn = V0 (1-r)n 
 *
 *設計C語言程式計算其殘值。(檔名 hw01-03.c)
 */



#include <stdio.h>
#include <stdlib.h>

double compute_value (double value, int year, double degradation)
{
	if (year < 0)
		return -1;
	while (year != 0) {
		value = value * (1-degradation);
		year --;
	}
	return value;
}



int main ()
{
	// variables
	double initial_value, final_value, degradation;
	int years;

	// input
	printf("請輸入原值：\n");
	scanf("%lf", &initial_value);

	printf("請輸入年折舊率：\n");
	scanf("%lf", &degradation);

	printf("請輸入計算的年份：\n");
	scanf("%d", &years);


	// process
	final_value = compute_value (initial_value, years, degradation);	


	// output
	printf("The remaining value is as follow: %lf\n", final_value);

	return 0;
}
