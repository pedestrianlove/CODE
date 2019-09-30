#include <stdio.h>

int main ()
{
	// Variables
	int age, height, money;

	
	// Input
	printf ("Please input your personal data:\n");
	
	printf ("AGE:\n");
	scanf ("%d", &age);

	printf ("HEIGHT:\n");
	scanf ("%d", &height);

	printf ("INCOME PER MONTH:\n");
	scanf ("%d", &money); //我diagram寫成300000,應該是30000

	
	// Process && Output
	if (age > 30  ||  age < 25 )
		printf ("NO!\n");
	else if (height < 160  ||  height > 175)
		printf ("NO!\n");
	else if (money < 30000)
		printf ("NO\n");
	else
		printf ("YES!\n");

	return 0;
}
