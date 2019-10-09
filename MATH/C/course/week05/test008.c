#include <stdio.h>


int main ()
{
	// input year
	printf ("Input a year:\n");
	int year;
	scanf ("%d", &year);

	char YEAR[13][100] = {"鼠", "牛", "虎", "兔", "龍", "蛇", "馬", "羊", "猴", "雞", "狗", "豬"};
	// check error input && process input
	if (year <= 12 && year >= 1) {
		printf ("%d ---> %s\n", year, YEAR[year-1]);	
	}
	else
		printf ("請重新輸入!\n");



	return 0;
}
