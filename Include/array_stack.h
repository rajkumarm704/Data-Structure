#ifndef ARRAY_STACK
#define ARRAY_STACK

typedef int data_t;

typedef enum 
{
	stack_does_not_exist_failure, max_size_failure, mem_alloc_failure, stack_empty_failure, success, mem_alloc_success
}bool_arr_stack;

typedef struct _array_stack_t
{
	data_t *array;
	size_t size;
	int top;
}array_stack_t;

//Create array stack
bool_arr_stack create_array_stack(array_stack_t *s);

//Push data into array stack
bool_arr_stack push_array(array_stack_t *s, data_t data);

//Pop array stack
bool_arr_stack pop_array(array_stack_t *s);

//Peep array stack
bool_arr_stack peep_array(array_stack_t *s);


#endif
