#include<stdio.h>
#include<stdlib.h>

void clear_word(char* word)
{
	memset(word, 0, sizeof(word));
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

int main()
{
	// HANDLE BASIC PARAMETER
	int dim;
	scanf("%d\n", &dim);
	char puzzle[dim][dim+1];
	char *word;
	word = (char*) malloc((dim*dim+1)*sizeof(char));
	char temp;
	
	// TRAVERSE
	for(int rows = 0; rows < dim; rows++)
		for(int cols = 0; cols < dim; cols++){
			if(check_vowel(puzzle[rows][cols])){
				int i = rows, j = cols;
				save(word, puzzle[rows][cols]);
				while(traverse(i, j, &temp, puzzle[][])){
					



				}
				clear_word(word);	
			}
			
		}
	free(word);
	return 0;
}
