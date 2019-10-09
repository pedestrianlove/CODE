#include <stdio.h>
#include <stdlib.h>

// Voting population && election entries
#define M 50
#define N 7


int main ()
{	
	// init the rand () seed
	srand (time(NULL));


	// variables
	int votes[N+1];
	for (int i = 0; i < N; i++)
		votes[i] = 0;

	// simulation
	for (int i = 0; i < M; i++) {
		votes[rand()%(N+1)]++;
	}

	// analyze the outcome
	int vote_sum = 0;
	for (int i=  0; i < N; i++) {
		printf ("%d elect got %d votes!\n", i+1, votes[i]);
		vote_sum += votes[i]
	}

	// analyze the ditched votes
	vote_sum += votes[N];
	float ditched = (float) votes [N];
	printf ("%d person ditched their votes, with the percentage of %f%c \n", ditched, (ditched/vote_sum)*100, '%');
	


	return 0;
}
