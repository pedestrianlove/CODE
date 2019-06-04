#include<stdio.h>

int main()
{
	char s[1000001];

	int strlen;


	while(scanf("%s%n\n", s, &strlen)!= EOF)
	{
		for(int i = strlen-1; i >=0; i--)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}
