#include<stdio.h>
#include<stdlib.h>
#include<dlist.h>


//Display double link list
bool_t dl_display_list(dlist_t **head)
{
	if ( *head == NULL )
		return failure;
	else
	{
		dlist_t *ptr = *head;

		printf("Data:");
		while( ptr->next != NULL )
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;

		}//while

		printf("%d\n", ptr->data);

	}//else

}

//Insert data at last of link list
bool_t dl_insert_last(dlist_t **head, dlist_t **tail, data_t data)
{
	dlist_t *new = malloc( sizeof(dlist_t) );

	if ( new == NULL )
		return failure;

	new->prev = new->next = NULL;
	new->data = data;

	if( *head == NULL )
		*head = *tail = new;
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
		return success;
	}//else

}

//Insert data at last of link list
bool_t dl_insert_first(dlist_t **head, dlist_t **tail, data_t data)
{
	dlist_t *new = malloc( sizeof(dlist_t) );

	if ( new == NULL )
		return failure;

	new->prev = new->next = NULL;
	new->data = data;

	if( *head == NULL )
		*head = *tail = new;
	else
	{
		new->next = *head;
		*head = new;

	}//else


	return success;


}

//Delete first element of list
bool_t dl_delete_first(dlist_t **head)
{

	if( *head == NULL )
		return failure;
	else
	{
		dlist_t *ptr = *head;
		*head = (*head)->next;
		free(ptr);
		return success;

	}//else
}

//Delete last element of list
bool_t dl_delete_last(dlist_t **head, dlist_t **tail)
{

	if( *head == NULL )
		return failure;
	else
	{
		dlist_t *ptr = *tail, *prev = (*tail)->prev;
		prev->next = NULL;
		free(ptr);
		*tail = prev;
		return success;

	}//else
}

//Find the link length
bool_t dl_linklen(dlist_t **head)
{
	if( *head == NULL )
		return failure;
	else
	{
		int count = 0;
		dlist_t *ptr = *head;

		while( ptr->next != NULL )
		{
			count++;
			ptr = ptr->next;

		}//while
		
		printf("Link length is %d\n", ++count);

	}//else
}












