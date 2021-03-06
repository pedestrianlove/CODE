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
int COUNTER = 0;

// internal
void initialize_distro (char);
void mergesort_t (int, int);
void merge (int, int, int);
void append (node*, node*);
int clean_up_distro(int);
node* init_node (int sum);
char* reverse_string (char*);
void shift ();

// interface
void Prepare_distro ();
void Get_the_text (int);
void Sort_distro (int);
void Form_the_tree ();
char* Encode_the_char(char);

// debug
void _show_distro ();
void _show_the_tree (node*);


int main()
{
	int lines;
	char tmp;
	char* word = malloc (sizeof(char)* 101);
	scanf("%d%c%s", &lines, &tmp, word);
	Prepare_distro ();
		
	Get_the_text (lines);
	
	Sort_distro (COUNTER);
	printf("The COUNTER is %d\n", COUNTER);
	Form_the_tree ();
	_show_the_tree (distro[0]);

	char* encoded;
	for (int i = 0; i< strlen (word); i++) {
		encoded = Encode_the_char (word[i]);
		printf("%s", encoded);
		free (encoded);
	}
	printf("\n");

	free (word);
	return 0;
}


void Prepare_distro () 
{
	alpha = malloc (sizeof(node*) * 26);
	distro = malloc (sizeof(node*) * 26);
	for (int i = 0; i< 26; i++) {
		alpha[i] = NULL;
		distro[i] = NULL;
	}

}


void Get_the_text (int lines)
{
	int counter = 0;
	char* text = malloc (sizeof(char)* 101);
	while (scanf ("%s", text) != EOF){
		for (int j = 0; j < strlen (text); j++) {
			if (distro[text[j] - 'a'] == NULL) {
				counter++;
				initialize_distro(text[j]);
				alpha[text[j] - 'a'] = distro[text[j] - 'a'];
			}
			else
				distro[text[j] - 'a'] -> SUM++;
		}
	}
	COUNTER = counter;
	shift ();
	free (text);
}
void initialize_distro (char character)
{
	node* new = malloc (sizeof(node));
	new -> CHAR = character;
	new -> SUM = 1;
	new -> PARENT = NULL;
	new -> CHILD[0] = NULL;
	new -> CHILD[1] = NULL;
	new -> CHILD_NO = '3';

	// append the node to the list
	distro[character - 'a'] = new;
	alpha[character - 'a'] = new;
}
void shift ()
{
	int i = 0, real_counter = 0;
	while (i < 26) {
		if (distro[i] == NULL)
			i++;
		else {
			distro[real_counter++] = distro[i];
			distro[i++] = NULL;
		}
	}
}


void Sort_distro (int number)
{
	mergesort_t (0, number-1);
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
	

	node **left = malloc (sizeof(node*) * 30);
	for (int i = 0; i < 30 ; i++)
		left[i] = NULL;
       	node **right = malloc (sizeof(node*) * 30);
	for (int i = 0; i < 30 ; i++)
		right[i] = NULL;


	for (int i = start; i <= mid; i++)
		left[left_counter++] = distro[i];
	for (int i = mid+1; i<= end; i++)
		right[right_counter++] = distro[i];


	left_counter = right_counter = 0;	
	while (master_counter <= end){
		
		if (left[left_counter] == NULL) {
			distro[master_counter++] = right[right_counter++];
			continue;
		}
		if (right[right_counter] == NULL) {
			distro[master_counter++] = left[left_counter++];
			continue;
		}


		if (left[left_counter]->SUM <= right[right_counter]->SUM) {
			if (left[left_counter]->SUM == right[right_counter]->SUM) {
				if (left[left_counter]->CHAR == '~'  &&  right[right_counter]->CHAR != '~') {
					distro[master_counter++] = right[right_counter++];
					continue;
				}
			}
			distro[master_counter++] = left[left_counter++];
		}
		else {
			distro[master_counter++] = right[right_counter++];
		}
	}

	free (left);
	free (right);
}


void Form_the_tree ()
{
	//top = clean_up_distro (top);
	//_show_distro ();
	int top = COUNTER;
	while (distro[0] != NULL && distro[1] != NULL) {
			
		node* ptr = init_node (distro[0]->SUM + distro[1]->SUM);
		
		append (ptr, distro[0]);
		append (ptr, distro[1]);
		
		distro[0] = NULL;
		distro[1] = ptr;
		distro ++;
		
		Sort_distro (--top);
	}
	
	//_show_the_tree (distro[0]);
}
void _show_the_tree (node* ptr)
{
	// print the info
	printf("This node is of CHAR %c, SUM %d and CHILD_NO %c\n", ptr->CHAR, ptr -> SUM, ptr->CHILD_NO);
	for (int i = 0; i< 2; i++)
		if (ptr -> CHILD[i] != NULL)
			_show_the_tree (ptr->CHILD[i]);
}
node* init_node (int sum)
{
	node* new = malloc (sizeof(node));
	new -> SUM = sum;
	new -> CHILD[0] = NULL;
	new -> CHILD[1] = NULL;
	new -> PARENT = NULL;
	new -> CHILD_NO = '3';

	new -> CHAR = '~';
	return new;
}
int clean_up_distro (int numbers)
{
	while (distro[0]->SUM == 0) {
		distro[0] = NULL;
		
		distro++;
		numbers--;
	}
	return numbers;
}
void append (node* parent, node* child)
{
	if (parent -> CHILD[0] == NULL) {
		parent -> CHILD[0] = child;
		child -> CHILD_NO = '0';
		child -> PARENT = parent;
		return;
	}
	else if (parent -> CHILD[1] == NULL) {
		parent -> CHILD[1] = child;
		child -> CHILD_NO = '1';
		child -> PARENT = parent;
		return;
	}
	else
		printf("error, child bearing overload.\n");

}


char* Encode_the_char (char word)
{
	int counter = 0;
	char* tmp = malloc (sizeof(char) * 30);
	node* ptr = alpha[word-'a'];
	while (ptr -> CHILD_NO != '3') {
		tmp[counter++] = ptr -> CHILD_NO;
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
		tmp[counter++] = str[i];
	}
	free (str);
	return tmp;
}


void _show_distro ()
{
	printf("HI\n");
	for (int i = 0; distro[i] != NULL; i++)
		printf("distro '%d' is of CHAR %c and of SUM %d\n", i, distro[i] -> CHAR, distro[i] -> SUM);
}
