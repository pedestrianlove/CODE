#include <stdio.h>

int main ()
{
	// variables
	char tmp;
	int english, math, chinese;
	
	// input
	printf ("順序輸入英文 數學 國文三科成績 (各科之間以, 隔開)：");
	scanf ("%d%c%d%c%d", &english, &tmp, &math, &tmp, &chinese);

	// output
	printf ("三科總成績 = %d\n", english+math+chinese);

	return 0;
}
