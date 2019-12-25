#include <stdio.h>
#include <stdlib.h>

int main ()
{
	// assign filename
	char filename[] = "graph.txt";
	
	// open file
	FILE* graph;
	graph = fopen (filename, "r");

	// read file and output
	char tmp;
	printf ("\n");
	while (fscanf (graph, "%c", &tmp) != EOF) {
		printf ("%c", tmp);
	}
	printf ("\n");

	// close file
	fclose (graph);




	return 0;
}
