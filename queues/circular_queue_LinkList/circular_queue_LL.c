#include<stdio.h>
#include<stdlib.h>

#include"types.h"

//Create a new node
slist_t * create_node(data_t value)
{
	slist_t *new = malloc( sizeof(slist_t) );
	new->data = value;
	new->next = NULL;
	return new;
}


//Insert a node at last of link list
bool_queue_CLL sl_insert_last(slist_t **head, data_t value)
{
	if( *head == NULL )
	{
		*head = create_node(value);
	}
	else
	{
		slist_t *ptr = *head;
		while( ptr->next != NULL )
		{
			ptr = ptr->next;
		}//while

		ptr->next = create_node(value);
	}//else

	return success;

}

//Delete the first node
bool_queue_CLL sl_delete_first(slist_t **head)
{
	if( *head == NULL )
	{
		return queue_empty_failure;
	}
	else
	{
		slist_t *new = *head;
		*head = new->next;

		free(new);
		return success;

	}//else
}

//Display the list
bool_queue_CLL sl_display_list(slist_t **head)
{
	if( *head == NULL )
	{
		return queue_empty_failure;
	}
	else
	{
		slist_t *ptr_cur = *head;

		printf("Data:");
		while( ptr_cur->next != NULL )
		{
			printf("%d ", ptr_cur->data);
			ptr_cur = ptr_cur->next;
			
		}//while

		printf("%d\n", ptr_cur->data);
		
		return success;
	}//else

}

