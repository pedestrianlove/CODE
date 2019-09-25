#include <stdio.h>

int main ()
{
	// Variables
	int age, length, money;

	
	// Input
	printf ("Please input your personal data:\n");
	
	printf ("AGE:\n");
	scanf ("%d", &age);

	printf ("LENGTH:\n");
	scanf ("%d", &length);

	printf ("INCOME PER MONTH:\n");
	scanf ("%d", &money);

	
	// Process && Output
	if (AGE > 30  ||  AGE < 25 )
		printf ("NO!\n");
	else if (LENGTH < 160  ||  LENGTH > 175)
		printf ("NO!\n");
	else if (money < 300000)
		printf ("NO\n");
	else
		printf ("YES!\n");

	return 0;
}
