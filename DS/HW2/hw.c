#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// MAIN FLOW
void branching(int, int, char*, char**, char*[]); // MAIN FUNCTION
int check_route(int, int, char*, char**, char*[]); // return 1 if valid, 0 if invalid

// UTILITIES ( LOW LEVEL OPERATION )
int check_vowel(char); // return 1 if vowel
void deform(char*); // deform the non-qualified string
void output(char*); // print out the string in the specified format.
void save(char*, char); // save the char into string
int verify(char*); //verify if follow the (cv+)2+(c) rules, return 1 if yes
int check_boundary(int, int, int);
void clear_path(char*[]);
void clear_word(char*);
int verify_final(char*); // verify if the correct word end, return 1 if yes

int main()
{
	// REQUIRED CONST & VAR
	int dim;
	scanf("%d\n", &dim);
	char puzzle[dim][dim+1];
	char* word_buffer;
	
	word_buffer = (char*) malloc((dim*dim+1)*sizeof(char));
	char path[dim*dim][30];

	// INPUT DATA
	for(int i = 0; i< dim; i++)
		gets(puzzle[i]);

	// TRAVERSE THE PUZZLE
	// WITH THE ORDER "DOWN RIGHT UP LEFT"
	for(int rows = 0; rows<dim; rows++)
		for(int columns = 0; columns<dim; columns++){
			if(check_vowel(puzzle[rows][columns]))
				continue;
			save(word_buffer, puzzle[rows][columns]);
			while(verify(word))



			clear_word(word_buffer);
		}
	free(word_buffer);
	return 0;
}

// BRANCHING PROCESS
/*
void branching(int rows, int columns, char* word, char** puzzle, char* path[30])
{	
	//record path
	char temp[30];
	sprintf(temp, "%d %d", rows, columns);
	memcpy(path+strlen(path), temp, strlen(temp));

	// branch out
	//if(check_route)
	
	
}


int check_route(int rows, int columns, char* word, char** puzzle, char* path[30])
{		
	// check boundary
	int max = strlen(word); // max length of a row or column
	if(rows >= max || columns >= max || rows < 0 || columns < 0)
		return 0;

	// check redundant path(strcmp) return 0
	char* temp;
	temp = (char*) malloc(30*sizeof(char));
	sprintf(temp, "%d %d", rows, columns);
	// run through the path to check
	for(int i = 0; i < strlen(path); i++){
		if(strcmp(temp,path[i]))
			return 0;
	}	
	
	return 0;
}
*/

//(cv+)2+(c)

int verify_final(char* word)
{
	// check consonant count
	int count = 0;
	for(int i = 0; i< strlen(word); i++)
		if(!check_vowel(word[i]))
			count++;
	if(count < 3)
		return 0;
	// check last character consonant
	if(check_vowel(word[strlen(word)-1]))
		return 0;
	return 1;
	
}


int verify(char* word)
{
	// first char must be consonant
	if(check_vowel(word[0]))
		return 0;
	
	// check connected consonant
	for(int i = 0; i< strlen(word)-1; i++)
		if(!check_vowel(word[i]) && !check_vowel(word[i+1]))
			return 0;

	return 1;	
}

void deform(char* word)
{
	char consonant[strlen(word)+1], vowel[strlen(word)+1];
	// seperate consonants and vowels
	int j = 0, k = 0;
	for(int i = 0; i< strlen(word); i++){
		if(check_vowel(word[i])){
			consonant[j] = word[i];
			j++;
		}
		else{
			vowel[k] = word[i];
			k++;
		}
	}

	// fill back the deformed string
	memmove(word, vowel, strlen(vowel));
	memmove(word+strlen(vowel), consonant, strlen(consonant));
}

int check_vowel(char x)
{
	switch(x){
		case 'a': return 1;
		case 'e': return 1;
		case 'i': return 1;
		case 'o': return 1;
		case 'u': return 1;
		default: return 0;
	}
}

void output(char* word)
{
	// output the correct answer
	printf("%s ", word);

	// handle the deformed one
	char* temp;
	temp = (char*) malloc((strlen(word)+1)*sizeof(char));
	memcpy(temp, word, strlen(word));
	deform(temp);
	printf("%s\n", temp);
}
void save(char* word, char x)
{
	memmove(word+strlen(word), &x, 1);
}

void clear_path(char** path)
{
	memset(path, 0, sizeof(path));
}
void clear_word(char* word)
{
	memset(word, 0, sizeof(word));
}
