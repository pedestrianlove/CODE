#include <stdio.h>
#define MAXSIZE 2

struct test {
	int midtermGrade;
	int finalGrade;
};

int main ()
{
	struct test students[MAXSIZE] = {{65, 72}, {71, 85}};
	
	int sum = 0;
	for (int i=  0; i < 2; i++) {
		sum = students[i].midtermGrade + 
			students[i].finalGrade;
		printf ("成績平均: %.2f\n", sum/(float)MAXSIZE);
	}
	return 0;
}
