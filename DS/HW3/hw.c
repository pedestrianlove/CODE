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
	printf("HOE\n");
	bus_stop* ptr;
	ptr = NTHU;
	while(ptr != NULL){
		if(strcmp(ptr->NAME, src)==0 && strcmp(ptr->next->NAME, dst)==0){
			break;
		}
		printf("I CANT STOOOOOOOOOOOP!\n", ptr->next);
		ptr = ptr->next;
	}
	printf("HEY DONT GOOOOOOOOOO\n");
	return ptr;
}
bus_stop* INITIALIZE(char* bus_stop_name)
{
	bus_stop* new = malloc(sizeof(bus_stop));
	new->NAME = bus_stop_name;
	new->next = &new;
	new->previous = &new;
	return new;	
}
void CONNECT(bus_stop* a, bus_stop* b)
{
	a->next = b;
	b->previous = a;
}

// USER INTERFACE
void INSERT(char* src, char* dst, char* new, int method)
{
	printf("HI\n");
	// TRANSLATE char* into bus_stop node"TBD"
	bus_stop* SRC = FIND_BETWEEN(src, dst);
	bus_stop* DST = SRC->next;
	printf("HEHE");	
	// INITIALIZE THE "new" bus_stop
	bus_stop* NEW = INITIALIZE(new);
	printf("HOHO");
	// EXECUTE THE INSERT PART
	switch(method){
		case 1: // INSERT BETWEEN
			CONNECT(SRC, NEW);
			CONNECT(NEW, DST);	
		case 2: // IF POSSIBLE INSERT ON ANOTHER SIDE ALSO
			CONNECT(SRC, NEW);
			CONNECT(NEW, DST);
			if(DST->next == SRC){
				bus_stop* NEW_1 = INITIALIZE(new);
				CONNECT(DST, NEW_1);
				CONNECT(NEW_1, SRC);
			}
	}
}
void DELETE(char* bus_stop_name)
{
	bus_stop* ptr = NTHU->next;
	while(1){
		if(ptr==NTHU)
			break;
		if(ptr->NAME == bus_stop_name){
			ptr = ptr->next;
			_DELETE(ptr->previous);
		}
		ptr = ptr->next;
	}
}

// FOR DEBUG PURPOSE
void check(char* x)
{
	printf("%s\n", x);
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
	int method;
	char operation[7];
	char src[9], dst[9], new[9], del[9];
	for(int i = 0; i< number_of_operation; i++){
		//READ IN THE OPERATION
		scanf("%s", operation);
		check("CAN YOU SPEAK");
		if(operation[0] == 'I'){
			check("SURE");
			scanf("%s%s%s%d", src, dst, new, &method);
			INSERT(src, dst, new, method);
		}else{
			check("SOME");
			scanf("%s", del);
			DELETE(del);
		}		
	}
	check("FIN");
	// OUTPUT THE ROUTE
	bus_stop* ptr = NTHU;
	printf("%s", NTHU->NAME);
	while(ptr->next!=NTHU){
		ptr = ptr->next;
		printf("->%s", ptr->NAME);
	}
	printf("\n");

	// DELETE ALL THE REMAINING NODEs
	ptr = NTHU->next;
	while(ptr!=NTHU){
		ptr = ptr->next;
		_DELETE(ptr->previous);
	}
	_DELETE(NTHU);
}
