#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define number_of_characters 26
typedef struct node {
	int SUM; // sum of child(if any) freq
	char CHILD_NO;
	char CHAR;
	struct node* PARENT;
	struct node* CHILD[2];
}node;

node** distro;
node** alpha;

// internal
void initialize_distro (char);
void mergesort_t (int, int);
void merge (int, int, int);
void append (node*, node*);
void shift (int);
node* init_node (int sum);
char* reverse_string (char*);

// interface
void Prepare_distro ();
void Get_the_text (int);
void Sort_distro ();
void Form_the_tree ();
char* Encode_the_char(char);

void FREE (char*, char*);

int main()
{
	int lines;
	char tmp;
	char* word = malloc (sizeof(char)* 101);
	scanf("%d%c%s", &lines, &tmp, word);
	Prepare_distro ();
	
	Get_the_text (lines);
	printf("I'm alive\n");

	Sort_distro ();	

	Form_the_tree ();

	char* encoded;
	for (int i = 0; i< strlen (word); i++) {
		encoded= Encode_the_char (word[i]);
		printf("%s", encoded);
		free (encoded);
	}


	free (word);
	return 0;
}


void Prepare_distro () 
{
	alpha = malloc (sizeof(node*) * 26);
	distro = malloc (sizeof(node*) * 26);
	for (char i = 'a'; i<='z' ; i++) {
		initialize_distro (i);
	}
}
void initialize_distro (char character)
{
	node* new = malloc (sizeof(node));
	new -> CHAR = character;
	new -> SUM = 0;
	new -> PARENT = NULL;
	new -> CHILD[0] = NULL;
	new -> CHILD[1] = NULL;
	new -> CHILD_NO = '3';

	// append the node to the list
	distro[character - 'a'] = new;
	alpha[character - 'a'] = new;
}


void Get_the_text (int lines)
{
	char* text = malloc (sizeof(char)* 101);
	for (int i = 0; i< lines; i++) {
		while (scanf ("%s", text) != '\n'){
			for (int j = 0; j < strlen (text); j++) {
				distro[text[j] - 'a'] -> SUM++;
			}
		}
	}
	free (text);
}


void Sort_distro ()
{
	mergesort_t (0, 25);
}
void mergesort_t (int start, int end)
{
	if (start < end){
		int mid = start + (end - start) /2 ;
		mergesort_t (start, mid);
		mergesort_t (mid+1, end);
		merge (start, mid, end);
	}
}
void merge (int start, int mid, int end)
{
	int left_counter = 0,
	    right_counter = 0,
	    master_counter = start;
	
	node **left = malloc (sizeof(node*) * (mid-start + 1));
	for (int i = 0; i < mid-start+1 ; i++)
		left[i] = NULL;
       	node **right = malloc (sizeof(node*) * (end - mid + 1));
	for (int i = 0; i < end-mid+1 ; i++)
		right[i] = NULL;

	for (int i = start; i <= mid; i++)
		left[i] = distro[i];
	for (int i = mid+1; i<= end; i++)
		right[i] = distro[i];
	
	while (left_counter < mid-start+1  &&  right_counter < end-mid+1  &&  master_counter <= end){
		if (left[left_counter]->SUM <= right[right_counter]->SUM) 
			distro[master_counter++] = left[left_counter++];
		else
			distro[master_counter++] = right[right_counter++];
	}

	free (left);
	free (right);
}


void Form_the_tree ()
{
	int i = 0;
	int top = number_of_characters;
	while (distro[i] != NULL && top >= 2) {
		node* ptr = init_node (distro[0]->SUM + distro[1]->SUM);
		
		append (ptr, distro[0]);
		append (ptr, distro[1]);
		
		distro[0] = ptr;
		distro[1] = NULL;
		
		shift (--top);
		Sort_distro ();
	}
}
node* init_node (int sum)
{
	node* new = malloc (sizeof(node));
	new -> SUM = sum;
	new -> CHILD[0] = NULL;
	new -> CHILD[1] = NULL;
	new -> PARENT = NULL;
	new -> CHILD_NO = '3';

	new -> CHAR = 'X';
	return new;
}
void shift (int numbers)
{
	int counter = 0;
	int i = 0;
	while (counter < numbers) {
		while (distro[i] == NULL) {
			i++;
		}
		distro[counter++] = distro[i];
	}
}
void append (node* parent, node* child)
{
	if (parent -> CHILD[0] == NULL) {
		parent -> CHILD[0] = child;
		child -> CHILD_NO = '0';
		return;
	}
	else if (parent -> CHILD[1] == NULL) {
		parent -> CHILD[1] = child;
		child -> CHILD_NO = '1';
		return;
	}
	else
		printf("error, child bearing overload.\n");

}


char* Encode_the_char (char word)
{
	int counter = 0;
	char* tmp = malloc (sizeof(char) * 30);

	node* ptr = alpha[word];
	while (ptr -> CHILD_NO != '3') {
		tmp[counter] = ptr -> CHILD_NO;
		counter++;
		ptr = ptr -> PARENT;
	}
	tmp = reverse_string (tmp);
	return tmp;
}
char* reverse_string (char* str)
{
	char* tmp = malloc (sizeof(char) * (strlen(str) + 1));
	int counter = 0;
	for (int i = strlen(str) -1; i >= 0; i--){
		tmp[counter] = str[i];
		counter++;
	}
	free (str);
	return tmp;
}
