#include <stdio.h>

struct test {
	char name[10];
	int grade;
};

void addTen (struct test* new_test)
{
	new_test -> grade += 10;
}

int main ()
{
	struct test ME = {"SAMSON", 50};
	addTen (&ME);

	// OUTPUT
	printf ("My name is %s, and my grade is %d.\n", ME.name, ME.grade);

	return 0;
}
