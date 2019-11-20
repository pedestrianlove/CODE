#include <stdio.h>

int main ()
{
	FILE* fp;
	fp = fopen (__FILE__, "r");

	char tmp;
	int line_no = 2;
	printf ("%3d|\t", 1);
	while (fscanf (fp,"%c", &tmp) != EOF) {
		printf ("%c", tmp);
		if (tmp == '\n') {
			printf ("%3d|\t", line_no);
			line_no++;
		}
	}
	printf ("\n");

	fclose (fp);

	return 0;
}
