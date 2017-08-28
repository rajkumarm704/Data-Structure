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

		printf("List is:");
		while( ptr )
		{
			printf("%d ", ptr->data);

			if ( ptr->next == NULL )
				break;

			ptr = ptr->next;

		}//while

		printf("\n");

		return success;

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
		(*head)->prev = new;
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

//Insert after an element
bool_t dl_insert_after(dlist_t **head, dlist_t **tail, data_t element, data_t data)
{

	dlist_t *ptr = *head;

	while( ptr )
	{
		if ( ptr->data == element )
		{
			dlist_t *new = malloc( sizeof( dlist_t ) );
			new->data = data;	

			if ( new == NULL )
				return failure;

			if( ptr->next == NULL )
			{
				new->next = NULL;
				ptr->next = new;
				new->prev = ptr;
				*tail = new;
				free(new);
				return success;

			}//if

			new->next = ptr->next;
			ptr->next->prev = new;

			ptr->next = new;
			new->prev = ptr;

			free(new);

		}//if

		ptr = ptr->next;
	}//while
		
	*tail = ptr;

		
	return success;


}

//Insert Before
bool_t dl_insert_before(dlist_t **head, dlist_t **tail, data_t element, data_t data)
{

	dlist_t *ptr = *head;
	dlist_t *prev = *head;

	while( ptr )
	{
		if ( ptr->data == element )
		{
			dlist_t *new = malloc( sizeof( dlist_t ) );

			new->data = data;
			new->prev = NULL;

			if( ptr == *head )
			{
				ptr->prev = new;
				new->next = ptr;
				*head = new;
				dl_display_list(head);
				return success;
			}//else
			else
			{
				ptr->prev->next = new;
				new->prev = ptr->prev;
				ptr->prev = new;
				new->next = ptr;

				dl_display_list(head);

			}//else

			return success;
		}//if

		if ( ptr->next == NULL )
			return data_not_found_failure;

		prev = ptr;
		ptr = ptr->next;
	

	}//while	

}


//Delete element
bool_t dl_delete_element(dlist_t **head, dlist_t **tail, data_t element)
{
	if ( *head == NULL )
		return failure;
	else
	{
		dlist_t *ptr = *head;
		int flag = 0;

		while( ptr )
		{


			if ( ptr->data == element )
			{
				flag = 1;

				if ( ptr == *head )
					dl_delete_first(head);
				else if ( ptr == *tail )
					dl_delete_last( head, tail );
				else
				{
					ptr->next->prev = ptr->prev;
					ptr->prev->next = ptr->next;
					free(ptr);

				}//else

			}//if

			if ( ptr->next == NULL )
			{
				if ( flag == 1 )
					return success;
				else if ( flag == 0 )
					return data_not_found_failure;
			}

			ptr = ptr->next;
			
		}//while
	
	}//else

}



//Delete list
bool_t dl_delete_list(dlist_t **head, dlist_t **tail)
{
	//Check if list exists; return failure if true
	if ( *head == NULL )
		return failure;
	else
	{
		dlist_t *ptr = *head;
		while( ptr )
		{
			if ( ptr->next == NULL )
			{
				*head = NULL;
				*tail = NULL;
				return success;
			}//if

			ptr = ptr->next;
			free( ptr->prev );
			
		}//while

	
	}//else

}




