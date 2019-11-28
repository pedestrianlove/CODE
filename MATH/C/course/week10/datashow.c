#include <stdio.h>

int main() 
{
	// print header
	printf("Content-Type: text/html;charset=utf-8\n\n");
	
	// open file
	FILE* fp = fopen ("../../data/math171002mu.txt", "r");
	
	// read the file and output
	char id[80];
	char name[80];
	char email[80];
	while (fscanf (fp, "%s%s%s", id, name, email) != EOF) {
		printf ("%s\t%s\t%s", id, name, email);
		printf ("<br />");
	}

	// cleaning up...
	fclose (fp);
	return 0;
}
