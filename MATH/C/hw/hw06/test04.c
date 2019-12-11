#include <stdio.h>

typedef struct num {
	int data;
}num;

int main ()
{
	num number[10];
	number[1].data = 20;
	num* ptr = number;


	ptr ++;
	printf ("%d\n", ptr -> data);

}
