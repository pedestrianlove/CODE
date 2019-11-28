#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// USER DEFINED CONST
#define N 52

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
	for (int i = 0; i < N; i++)
		fscanf (fp, "%d", &SCORE[i]);
	
	fclose (fp);
	return SCORE;
}

int main (int argc, char* argv[])
{
	// init fileHandle
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
	printf ("SUM: %f\t MEAN: %f\n", SUM, AVG);
	printf ("MAX: %f\t MIN: %f\n", MAX, MIN);
	printf ("STD: %f\n", STD);

	// CLEANING UP ...
	free (SCORE);
	return 0;
}
