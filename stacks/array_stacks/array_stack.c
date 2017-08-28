#include<stdio.h>
#include<stdlib.h>
#include<array_stack.h>

//Create array stack
bool_arr_stack create_array_stack(array_stack_t *s)
{
	//Prompt user for size of stack
	printf("Enter the size of stack:"), scanf("%ld", &s->size );

	//Allocate memory for stack
	s->array = malloc( s->size * sizeof( data_t ) );

	//Intialise the top index to -1
	s->top = -1;

	//Check if memory was allocated
	if ( s->array != NULL )
		return mem_alloc_success;
	else
		return mem_alloc_failure;
}

//Push data into array stack
bool_arr_stack push_array(array_stack_t *s, data_t data)
{

	if ( s == NULL )
		return stack_does_not_exist_failure;
	else
	{
		data_t *ptr = s->array;

		//if top index is less than size of stack, increment the index and push the data into stack
		if ((s->top) < (int)(s->size))
		{
			(s->top)++;
			s->array[s->top] = data;
			return success;

		}//if

		//If top index is equal to size of stack, return stack full failure
		else if ( (s->top) == (int)(s->size) )
		{
			return max_size_failure;

		}//else if

	}//else

}

//Pop array stack
bool_arr_stack pop_array(array_stack_t *s)
{
	if ( s == NULL )
		return stack_does_not_exist_failure;
	else
	{
		//If top index if greater than 0, pop the element
		if ( s->top >= 0 )
		{
			(s->top)--;
			return success;
		}

		//If top index if smaller than 0, return stack empty failure
		else if ( s->top < 0 )
		{
			return stack_empty_failure;
		}
	}//else


}

//Peep array stack
bool_arr_stack peep_array(array_stack_t *s)
{
	if ( s == NULL )
		return stack_does_not_exist_failure;
	else
	{
		int i;

		if ( s->top < 0 )
			return stack_empty_failure;

		//Display all contents of stack
		for ( i = 0; i <= s->top; i++ )
		{
			printf("%d ",s->array[i]);
		}
		
		printf("\n");
	
		return success;
	}//else

}




