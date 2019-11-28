#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// GLOBAL VARIABLES
int N = 52;
int number_Count;
/**********************************************************/


// FUNCTION
void WRITE_FILE (char* filePath)
{
	// init srand seed
	srand (time (NULL));

	// open the file and write
	FILE* fp = fopen (filePath, "w");
	int tmp;
	for (int i = 0; i < N; i++) {
		tmp = rand ()  %  101;
		fprintf (fp, "%3d\n", tmp);
	}
	fclose (fp);
}

int* READ_FILE (char* filePath)
{
	// init array
	int* SCORE = malloc (sizeof (int) * N);
	for (int i = 0; i < N; i++)
		SCORE[i] = 0;

	// open the file and read
	FILE* fp = fopen (filePath, "r");
	number_Count = 0;
	while (fscanf (fp, "%d", &SCORE[number_Count]) != EOF) {
		number_Count ++;
	}
	
	fclose (fp);
	return SCORE;
}
/**********************************************************/



int main (int argc, char* argv[])
{
	// init argument
	char* fileHandle = argv[1];

	// write && read file
	WRITE_FILE (fileHandle);
	int* SCORE = READ_FILE (fileHandle);

	// obtain data from SCORE
	float SUM = 0,
	      AVG = 0,
	      MAX = SCORE[0],
	      MIN = SCORE[0],
	      STD = 0;	
	for (int i = 0 ; i < N; i++) {
		SUM += SCORE[i];
		MAX = (MAX < SCORE[i])?  SCORE[i]:MAX;
		MIN = (MIN > SCORE[i])?  SCORE[i]:MIN;
	}
	AVG = SUM/N;
	for (int i = 0; i < N; i++) {
		STD += pow (SCORE[i]-AVG, 2);
	}
	STD = STD/N;


	// OUTPUT
	printf ("We have %d terms in total.\n", number_Count);
	printf ("SUM: %f\t MEAN: %f\n", SUM, AVG);
	printf ("MAX: %f\t MIN: %f\n", MAX, MIN);
	printf ("STD: %f\n", STD);

	// CLEANING UP ...
	free (SCORE);
	return 0;
}
