#ifndef LINKLIST_STACK_H
#define LINKLIST_STACK_H

//User defined Data Type for data
typedef int data_t;

//User defined Data type for flag
typedef enum
{
	failure, success

}bool_ll_stack;

//slist structure
typedef struct _slist_t
{
	data_t data;
	struct _slist_t *next;
	int top;

}slist_t;


/*	Function Prototypes	*/

//Create Node
slist_t * create_node(data_t value);

//Insert data at first node
void sl_insert_first(slist_t **head, data_t value);

//Delete data at first node
void sl_delete_first(slist_t **head);

//Display data of the list
void sl_display_list(slist_t **head);

//Display the top data
void peep(slist_t **head);


#endif
