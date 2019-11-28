#include <stdio.h>

void enter (int times)
{
	printf ("<br />");
}

void table_open ()
{
	printf ("<table border=4 bordercolor=powderblue>");
}
void table_close ()
{
	printf ("</table>");
}

void row_open ()
{
	printf ("<tr>");
}
void row_close ()
{
	printf ("</tr>");
}
/*******************************************************************/
int main() 
{
	// print header
	printf ("Content-Type: text/html;charset=utf-8\n\n");
	printf ("MATH171002 程式設計I（華）\n");	
	enter (3);
	
	// open table
	table_open ();

	// open file
	FILE* fp = fopen ("../../data/math171002mu.txt", "r");

	// read the file and output
	char id[80];
	char name[80];
	char email[80];
	while (fscanf (fp, "%s%s%s", id, name, email) != EOF) {
		row_open ();
		printf ("<td>%s", id);
		printf ("<td>%s", name);
		printf ("<td>%s", email);
		row_close ();
	}

	// cleaning up...
	table_close ();
	fclose (fp);
	return 0;
}
