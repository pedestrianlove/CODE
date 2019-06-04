#include<stdio.h>
#include<stdlib.h>

// GLOBAL
int BOARD[3][3] = {0};

// Struct
typedef struct node
{
	int NODE_ID;
	int PARENT_ID;
	char MARK;
	int X_POS, Y_POS;
	
	// 2 distinct child pointer
	struct node* child[2];
}node;
// INTERNAL FUNCTION
int check_the_BOARD() // Return 1 or 0 depends on the solution existence of the BOARD
{
	// Lines to sum up
	int 	up 		= BOARD[0][0] + BOARD[1][0] + BOARD[2][0],
		down 		= BOARD[0][2] + BOARD[1][2] + BOARD[2][2], 
		right 		= BOARD[2][0] + BOARD[2][1] + BOARD[2][2], 
		left 		= BOARD[0][0] + BOARD[0][1] + BOARD[0][2], 
		mid_horizontal 	= BOARD[0][1] + BOARD[1][1] + BOARD[2][1], 
		mid_vertical 	= BOARD[1][0] + BOARD[1][1] + BOARD[1][2], 
		slant_left 	= BOARD[0][0] + BOARD[1][1] + BOARD[2][2], 
		slant_right 	= BOARD[2][0] + BOARD[1][1] + BOARD[0][2];

	if (	abs(up) 		== 3 ||
		abs(down) 		== 3 ||
		abs(right)		== 3 ||
		abs(left)		== 3 ||
		abs(mid_horizontal)	== 3 ||
		abs(mid_vertical)	== 3 ||
		abs(slant_left)		== 3 ||
		abs(slant_right)	== 3)
		return 1;
	else
		return 0;

}

void print (node* ptr)
{
	if(ptr -> child[0] != NULL)
		print (ptr -> child[0]);
	if(ptr -> child[1] != NULL)
		print (ptr -> child[1]);
	printf("%d %d %c\n", ptr -> X_POS, ptr -> Y_POS, ptr -> MARK);
}
void write_board (node* ptr)
{
	if (ptr->MARK == 'O')	BOARD[ptr->Y_POS][ptr->X_POS] = 1;
	else			BOARD[ptr->Y_POS][ptr->X_POS] = -1;
}
void revert_board_changes (node* ptr)
{
	BOARD[ptr->Y_POS][ptr->X_POS] = 0;
}
void board_show (void)
{
	// Print out the BOARD
	for(int i = 0; i< 3; i++){
		for(int j = 0; j< 3; j++){
			switch(BOARD[i][j]){
				case 1:{
					 printf("O");
					 break;
				}
				case -1:{
					printf("X");
					break;
				}
				case 0:{
					printf("_");
					break;
				}
				default:{
					printf("ERROR_CORRUPTED_BOARD\n");
				}
			}
			if(j==2)
				printf("\n");
			else
				printf(" ");
		}
	}
}

// User Interface
node* INITIALIZE (int node_id, int parent_id, int x_pos, int y_pos, char mark, node* pointer_index[])
{
	// Allocate the space
	node* new_node = malloc(sizeof(node));
	// Assign the value as required

	new_node -> NODE_ID 	= node_id;
	new_node -> MARK	= mark;
	new_node -> X_POS	= x_pos;
	new_node -> Y_POS	= y_pos;
	new_node -> PARENT_ID	= parent_id;
	new_node -> child[0]	= NULL;
	new_node -> child[1]	= NULL;
	// Record the pointer in the array
	pointer_index[node_id] = new_node;
	
	return new_node;
}
void ATTACH (node* node_ptr, node* parent_ptr)
{
	int i = 0;
	for (int i = 0; i< 2; i++)
		if (parent_ptr->child[i]==NULL){
			parent_ptr->child[i] = node_ptr;
			return;
		}
	
	// O.W, print out error
	printf ("Child bearing overload...\n");

}
//			For falling back to parent	Position to start the traversal
int FIND_ANSWER ( 	node** node_index,	 	node* current_node)
{
	// Record the node data on the BOARD
	write_board (current_node);
	// Traverse the node
	for(int i = 0; i < 2; i++){
		if (current_node -> child[i] != NULL)
			if(FIND_ANSWER (node_index, current_node -> child[i]))
				return 1; // KEEP THE BOARD IF FOUND
			else{
				continue;
			}
		else{

			if(check_the_BOARD()){ 
				return 1; // KEEP THE BOARD IF FOUND
			}

			else{
				continue;
			}
		}
	}

	// RESET IF NOT FOUND
	revert_board_changes (current_node);
	return 0;
}


void OUTPUT (char flag, node* ptr) 
{
	// Check the flag:
	if(flag == 'W'){
		printf("Win\n");
		board_show();
	}
	else{
		// Print out the tree by the postorder traversal
		printf ("Tie\n");
		print (ptr);
	}
}
int main()
{
	// Prepare for the data input
	int number_of_instructions;
	scanf ("%d", &number_of_instructions);

	// Make an array for indexing node's pointer
	node** pointer_index =  malloc(sizeof(node*)*number_of_instructions);

	// Record the tree
	node* temp;
	int node_id, parent_id, x_pos, y_pos;
       	char mark;	
	for (int i = 0; i< number_of_instructions; i++){
		// Read in the instructions:    node		parent_id	x_pos	y_pos	mark
		scanf ("%d%d%d%d %c", 		&node_id, 	&parent_id, 	&x_pos, &y_pos, &mark);
		temp = INITIALIZE (		node_id, 	parent_id, 	x_pos, 	y_pos, 	mark,	pointer_index);
		// Process the nodes
		if (node_id == 0) continue; // Skip the first "-1" case
		ATTACH (temp , pointer_index[parent_id]); 
	}
	

	// Traverse through the tree and find out if the tree has a solution
	// Need to travel down the path and switch the branch when needed
	if(FIND_ANSWER (pointer_index, pointer_index[0])== 0)
		OUTPUT ('T', pointer_index[0]); 
	else
		OUTPUT ('W', pointer_index[0]);

	// Free the space used
	for(int i = 0; i< number_of_instructions; i++)
		free(pointer_index[i]);		
	free(pointer_index);
	return 0;
}
