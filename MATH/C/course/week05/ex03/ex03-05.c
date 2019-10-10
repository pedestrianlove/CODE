#include <stdio.h>
#include <math.h>

double one (int N)
{
	double sum = 0;
	for (int i = 0; i < N; i++) {
		if ((i+1)%2 == 1)
			sum += (i+1);
	}
	return sum;
}

double two (int N)
{
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += pow (0.06, i+1);
	}
	return sum;
}

double three (int N)
{
	double sum = 0;
	for (double i = 0; i < N; i++) {
		sum += 1/(i+1);
	}
	return sum;
}

double four (int N)
{
	double sum = 0;
	for (int i = 0; i <= N; i++) {
		sum += pow(0.5, i);
	}
	return sum;
}

double five (int N)
{
	double sum = 1;
	for (int i = 2; i <= N; i++) {
		sum *= (1-(1/i)) ;
	}
	return sum;
}

int main ()
{
	int N, CALC;
	printf ("Please input a kind of calculation you desires:\n");
	scanf ("%d", &CALC);
	printf ("Please input a number N:\n");
	scanf ("%d", &N);

	double ANS;
	switch (CALC) {
		case 1:
			ANS = one (N);
			break;
		case 2:
			ANS = two (N);
			break;
		case 3:
			ANS = three (N);
			break;
		case 4:
			ANS = four (N);
			break;
		case 5:
			ANS = five (N);
			break;
		default:
			printf ("INPUT ERROR! PLEASE TRY AGAIN LATER!\n");
	}
	
	// OUTPUT
	printf ("The answer is %.3lf\n", ANS);

	return 0;
}
