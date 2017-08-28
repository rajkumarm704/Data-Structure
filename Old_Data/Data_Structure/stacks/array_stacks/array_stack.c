#include<stdio.h>
#include<stdlib.h>
#include<array_stack.h>

//Create array stack
bool_arr_stack create_array_stack(array_stack_t *s)
{

	printf("Enter the size of stack:"), scanf("%ld", &s->size );
	s->array = malloc( s->size * sizeof( data_t ) );
	s->top = -1;

	if ( s != NULL )
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

		if ( (s->top) < (int)(s->size) )
		{
			(s->top)++;
			s->array[s->top] = data;
			return success;

		}//if
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
		if ( s->top >= 0 )
		{
			(s->top)--;
			return success;
		}
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

		for ( i = 0; i <= s->top; i++ )
		{
			printf("%d ",s->array[i]);
		}
		
		printf("\n");
	
		return success;
	}//else

}




