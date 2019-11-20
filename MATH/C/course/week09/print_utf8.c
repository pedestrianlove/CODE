#include <stdio.h>

void print_file (char*);

int main ()
{
	print_file ("data/math171002mu.txt");

	return 0;
}

void print_file (char* file_path)
{
	// variables
	char name[80];
	char number[80];
	char email[80];

	// open file
	FILE* fp = fopen (file_path, "r");


	while (fscanf (fp, "%s %s %s", number, name, email) != EOF) {
		printf ("%s\t%s\t%s\n", number, name, email);
	}

	fclose (fp);
}
