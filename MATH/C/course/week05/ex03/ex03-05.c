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
		sum += 1/(i+1)
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
	int CALC;
	printf ("Please input a kind of calculation you desires:\n")
	scanf ("%d", &CALC);
	printf ("Please input a number N:\n")
	scanf ("%d", &N);

	double ANS;
	switch (CALC) {
		case 1:
			ANS = one ();
			break;
		case 2:
			ANS = two ();
			break;
		case 3:
			ANS = three ();
			break;
		case 4:
			ANS = four ();
			break;
		case 5:
			ANS = five ();
			break;
		default:
			printf ("INPUT ERROR! PLEASE TRY AGAIN LATER!\n");
	}
	
	// OUTPUT
	printf ("The answer is %lf", ANS);

	return 0;
}
