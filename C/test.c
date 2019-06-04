#include<stdio.h>
#include<stdlib.h>

int find_max_sum(int* price, int length, int length_needed)
{
	//We have price, length of price array
	//Hence, we can compute the maximal price possible by
	
	//Find the maximum price per volume ratio
	float max_ratio = 0;
	int max_count;
	for(int i = 0; i < length; i++)
	{
		if((float)price[i]/(i+1) > max_ratio && i<length_needed)
		{
			max_ratio = (float)price[i]/(i+1);
			max_count = i;
		}
	}
	if(length_needed == 0)
	{
		return 0;
	}
	if(length_needed == 1)
	{
		return price[max_count];
	}

	//Try to fill up the 'length' space as much as possible with the maximal priced cake size
	return price[max_count]*(max_count+1)+find_max_sum(price,length, length_needed-max_count-1 );
}



int main()
{
	//VARIABLES USED
	int price_buffer;
	int *price_record = NULL;
	size_t counter = 0;

	//PROCESS: INPUT DATA
	while(scanf("%d", &price_buffer) != EOF)
	{
		counter++;
		int *temp_array = realloc(price_record, (counter)*sizeof(int));
		if(temp_array != NULL)
		{
			price_record = temp_array;
			price_record[counter-1] = price_buffer;
		
		}
	}	
	//PROCESS: TRIAL AND ERROR
	printf("%d", find_max_sum(price_record, (int)counter, (int)counter));


	return 0;
		

}
