#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// global
char** BOARD;
int** PATH;
char* tmp;
int dim;

// internal
int check_vowel (char);
void pop ();
void append (int , int);
int check_boundary (int, int);
void print_the_word ();
int check_valid ();
int finished ();

// interface
void Get_input ();
void Find_word (int, int);

// debug
void _print_board (int);

int main()
{
	Get_input ();
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			printf("-------------------\n");
			fflush(stdout);
			Find_word (i, j);
		}
	
	return 0;
}


void Get_input ()
{
	scanf("%d", &dim);
	BOARD = malloc (sizeof(char*) * dim);
	tmp = malloc (sizeof(char*) * (dim*dim + 1));
	for (int i = 0; i < dim; i++)
		BOARD[i] = malloc (sizeof(char) * (dim+1));
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			scanf(" %c", &BOARD[i][j]);

	PATH = malloc (sizeof(int*) * dim);
	for (int i = 0; i < dim; i++)
		PATH[i] = malloc (sizeof(int) * dim);
}


void Find_word (int x, int y)
{
	printf("Currently at x=%d, y=%d, tmp=%s\n", x, y, tmp);
	fflush (stdout);
	// write in the effect
	append (x, y);

	// check if valid or revert and break;
	if (check_valid ())
		if (finished ())
			print_the_word ();
	else {
		pop ();
		return;
	}	

	
	// branch
	if (check_boundary (x-1, y) && PATH[x-1][y] == 0)
		Find_word (x-1, y);
	if (check_boundary (x, y+1) && PATH[x][y+1] == 0)
		Find_word (x, y+1);
	if (check_boundary (x+1, y) && PATH[x+1][y] == 0)
		Find_word (x+1, y);
	if (check_boundary (x, y-1) && PATH[x][y-1] == 0)
		Find_word (x, y-1);


	// remove the effect
	pop ();
	return;
}
void init_path ()
{
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			PATH[i][j] = 0;
}
int finished ()
{
	if (strlen(tmp) < 5)
		return 0;
	if (check_vowel (tmp[strlen(tmp)-1]) != 0)
		return 0;
	else
		return 1;
}
int check_valid ()
{
	if (check_vowel (tmp[0]) != 0)
		return 0;
	for (int i = 0; i < strlen(tmp); i++)
		if ((!check_vowel (tmp[i]))  &&  (!check_vowel(tmp[i+1])))
			return 0;
	return 1;
}
void append (int x, int y)
{
	tmp[strlen(tmp)] = BOARD[x][y];
	PATH[x][y] = 1;
}
void pop ()
{
	memset (tmp+strlen(tmp), 0, sizeof(char));
}
void print_the_word ()
{
	printf("%s ", tmp);
	for (int i = strlen(tmp)-1; i >= 0; i--)
		printf("%c", tmp[i]);
	printf("\n");
}
int check_boundary (int x, int y)
{
	if (x < dim && y < dim && x >=0 && y >= 0)
		return 1;
	else
		return 0;
}
int check_vowel (char x)
{
	switch (x) {
		case 'a': 
			return 1;
			break;
		case 'e': 
			return 1;
			break;
		case 'i':
			return 1;
			break;
		case 'o':
			return 1;
			break;
		case 'u':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}


void _print_board (int dim)
{
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++)
			printf("%c", BOARD[i][j]);
		printf("\n");
	}
}
