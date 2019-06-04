#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bus_stop{
	struct bus_stop* previous;
	struct bus_stop* next;
	char* NAME;
}bus_stop;
// PUBLIC DATA
bus_stop* NTHU;

// LOW LEVEL UTILITY
void _REV(bus_stop* bus_stop_node)
{
	bus_stop* temp;
	temp = bus_stop_node->next;
	bus_stop_node->next = bus_stop_node->previous;
	bus_stop_node->previous = temp;
}
void _DELETE(bus_stop* bus_stop_node)
{
	// VARIABLES
	bus_stop* next = bus_stop_node->next;
	bus_stop* previous = bus_stop_node->previous;
	
	// DELETE THE LINK
	next->previous = previous;
	previous->next = next;

	// FREE THE SPACE
	free(bus_stop_node);
}
bus_stop* FIND_BETWEEN(char* src, char* dst)
{
	bus_stop* ptr;
	ptr = NTHU;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->NAME, src)==0 && strcmp(ptr->next->NAME, dst)==0){
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}
bus_stop* INITIALIZE(char* bus_stop_name)
{
	bus_stop* new;
	// ALLOCATE THE SPACE FOR bus_stop_name duplication
	new = (bus_stop*) malloc(sizeof(bus_stop));
	char* NAME = malloc(sizeof(char)*(strlen(bus_stop_name)+1));

	// MAKE A COPY AND ASSIGN THE POINTER TO new->NAME
	memcpy(NAME, bus_stop_name, strlen(bus_stop_name));
	new->NAME = NAME;

	// MISCELLANEOUS
	new->next = NULL;
	new->previous = NULL;

	// RETURN THE OBTAINED POINTER
	return new;	
}
void CONNECT(bus_stop* a, bus_stop* b)
{
	a->next = b;
	b->previous = a;
}

// USER INTERFACE
void check_repetition(void)
{
	bus_stop* ptr = NTHU;
	while(ptr->next!=NULL){
		if(strcmp(ptr->NAME, ptr->next->NAME)==0){
			ptr = ptr->next;
			_DELETE(ptr->previous);
		}
		if(ptr == NTHU)
			break;
	}
}

void INSERT(char* src, char* dst, char* new, int method)
{    
	// TRANSLATE char* into bus_stop node"TBD"
	bus_stop* SRC = FIND_BETWEEN(src, dst);
	bus_stop* DST = SRC->next;
	// INITIALIZE THE "new" bus_stop
	bus_stop* NEW = INITIALIZE(new);
	// EXECUTE THE INSERT PART
	switch(method){
		case 1: // INSERT BETWEEN
			CONNECT(SRC, NEW);
			CONNECT(NEW, DST);
			break;
		case 2: // IF POSSIBLE INSERT ON ANOTHER SIDE ALSO
			CONNECT(SRC, NEW);
			CONNECT(NEW, DST);
			bus_stop* ptr = NTHU;
			bus_stop* NEW_1 = INITIALIZE(new);
			while(ptr!= NULL){
				//B|ACB && ACB|A
				if(strcmp(ptr->NAME, DST->NAME)==0 && strcmp(ptr->next->NAME, SRC->NAME)==0){
					CONNECT(NEW_1, ptr->next);
					CONNECT(ptr, NEW_1);
					break;
				}
				ptr = ptr->next;
				// END THE LOOP	
				if(ptr == NTHU)
					break;
			}			
			break;
	}
}
void DELETE(char* bus_stop_name)
{
	bus_stop* ptr = NTHU->next;
	while(ptr!=NULL){
		if(ptr==NTHU)
			break;
		if(strcmp(ptr->NAME,bus_stop_name)==0){
			ptr = ptr->next;
			_DELETE(ptr->previous);
		}
		else
			ptr = ptr->next;
	}
}
void output(void)
{
	bus_stop* buffer = NTHU;
	printf("%s", NTHU->NAME);
	while(buffer->next!=NTHU){
		if(strcmp(buffer->NAME, buffer->next->NAME)==0){
			buffer = buffer -> next;
			continue;
		}
		buffer = buffer->next;
		printf("->%s", buffer->NAME);
		
	}
	printf("->NTHU\n");
}
void REV(void)
{
	bus_stop* ptr = NTHU;
	while(ptr!=NULL){
		_REV(ptr);
		ptr = ptr->previous;
		if(ptr == NTHU)
			break;
	}
}
void report(char* operation, char* src, char* dst, char* new, int method, char* del)
{
	switch(operation[0]){
		case 'I':
			printf("I INSERTED %s BETWEEN %s AND %s BY MODE %d\n", new, src, dst, method);
			break;
		case 'D':
			printf("I DELETED %s\n", del);
			break;
		case 'R':
			printf("I REVERSED\n");
			break;
	}
}

int main()
{
	// MISCELLANEOUS 
	int number_of_operation;
	scanf("%d", &number_of_operation);
	
	// PREDEFINED BUS STOPS
	NTHU = INITIALIZE("NTHU");
	bus_stop* TSMC = INITIALIZE("TSMC");
	CONNECT(NTHU, TSMC);
	CONNECT(TSMC, NTHU);	
	// EXECUTE OPERATION
	char operation[8];
	char src[9], dst[9], new[9], del[9];


	int method;
	for(int i = 0; i< number_of_operation; i++){
		//output(); // FOR TESTING PURPOSE
		//READ IN THE OPERATION
		scanf("%s", operation);
		if(strcmp(operation, "INSERT")==0){
			scanf("%s%s%s%d", src, dst, new, &method);
			INSERT(src, dst, new, method);
		}else if(strcmp(operation, "DELETE")==0){
			scanf("%s", del);
			DELETE(del);
		}else{
			REV();			
		}
		//report(operation, src, dst, new, method, del);
	}
	
	// OUTPUT THE ROUTE
	output();	
	// DELETE ALL THE REMAINING NODEs
	bus_stop* ptr;
	ptr = NTHU->next;
	while(ptr!=NTHU){
		ptr = ptr->next;
		_DELETE(ptr->previous);
	}
	_DELETE(NTHU);
	return 0;
}



