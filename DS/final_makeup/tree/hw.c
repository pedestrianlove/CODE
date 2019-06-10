#include<stdio.h>
#include<stdlib.h>

char BOARD[3][3];
char TARGET_BOARD[3][3];
int PATH[100];
int COUNTER = 0;
typedef struct node {
	int NODE_ID;
	int PARENT_ID;
	int X_POS, Y_POS;
	char MARK;
	struct node* child[2];
}node;


// internal
int check_the_board ()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (BOARD[i][j] != TARGET_BOARD[i][j])
				return 0;
	return 1;
}
void write_the_board (node* ptr)
{
	if (ptr->MARK=='O')
		BOARD[ptr->Y_POS][ptr->X_POS] = 'O';
	else
		BOARD[ptr->Y_POS][ptr->X_POS] = 'X';
}
void reset_the_board(node* ptr)
{
	BOARD[ptr->Y_POS][ptr->X_POS] = '_';
}
void print_node (node* ptr)
{
	PATH[COUNTER] = ptr -> NODE_ID;
	COUNTER++;
}

// interface
node* INITIALIZE (int node_id, int parent_id, int x_pos, int y_pos, char mark, node** index_list)
{
	node* new_node = malloc (sizeof(node));
	new_node -> NODE_ID = node_id;
	new_node -> X_POS = x_pos;
	new_node -> Y_POS = y_pos;
	new_node -> MARK = mark;
	new_node -> PARENT_ID = parent_id;


	index_list [node_id] = new_node;
	return new_node;
}
void APPEND (node* ptr, node ** index_list)
{
	node* parent = index_list[ptr -> PARENT_ID];
	for (int i = 0; i < 2; i++) {
		if (parent->child[i] == NULL) {
			parent->child[i] = ptr;
			return;
		}
	}
}
void BOARD_SCAN ()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf(" %c", &TARGET_BOARD[i][j]);
}
int FIND_PATH (node* ptr)
{
	write_the_board (ptr);
	for (int i = 0; i < 2; i++)
		if (ptr -> child[i] != NULL) {
			if (FIND_PATH(ptr->child[i])) {
				print_node (ptr);
				return 1;
			}
			else
				continue;
		}
		else {
			if (check_the_board ()) {
				print_node (ptr);
				return 1;
			}
			else
				continue;
		}

	reset_the_board (ptr);
	return 0;
}
void PRINT_PATH ()
{
	for (int i = COUNTER-1; i>= 0; i--) {
		if (i == 0){
			printf("%d\n", PATH[i]);
			break;
		}
		printf("%d ", PATH[i]);
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			BOARD[i][j] = '_';
			TARGET_BOARD[i][j] = '_';
		}

	for (int i = 0; i < 100; i++)
		PATH[i] = -1;

	int number_of_nodes;
	scanf("%d", &number_of_nodes);

	node** index_list = malloc (sizeof(node*) * number_of_nodes);
	node* current_node;

	int node_id, parent_id, x_pos, y_pos;
	char mark;

	for (int i = 0; i < number_of_nodes; i++) {
		scanf("%d%d%d%d %c", &node_id, &parent_id, &x_pos, &y_pos, &mark);
		current_node = INITIALIZE (node_id, parent_id, x_pos, y_pos, mark, index_list);
		if (current_node -> NODE_ID != 0)
			APPEND(current_node, index_list);
	}

	BOARD_SCAN();

	if (FIND_PATH(index_list[0])) {
		PRINT_PATH ();
	}
	else
		printf("ERROR_PATH_NOT_FOUND\n");

	for (int i = 0; i < number_of_nodes; i++)
		free (index_list[i]);
	free (index_list);

	return 0;
}
