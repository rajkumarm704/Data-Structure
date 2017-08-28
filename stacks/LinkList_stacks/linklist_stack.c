#include<stdio.h>
#include<stdlib.h>

#include"linklist_stack.h"

//Create a new node
slist_t * create_node(data_t value)
{
	//Allocate memory for new node
	slist_t *new = malloc( sizeof(slist_t) );
	new->data = value;

	//Make next link as NULL
	new->next = NULL;
	return new;
}

//Insert a node at first of link list
void sl_insert_first(slist_t **head, data_t value)
{
	//Create a list if no list exists
	if( *head == NULL )
	{
		*head = create_node(value);
		(*head)->top = 0;
	}

	//Insert a node at first of link list
	else
	{
		slist_t *new = create_node(value);
		new->next = *head;
		*head = new;
	}//else

	//Increment the top index
	(*head)->top++;

	printf("First node inserted.\n");
}

//Delete the first node
void sl_delete_first(slist_t **head)
{
	//Return if link does not exist
	if( *head == NULL || (*head)->top <= 0 )
	{
		printf("Nothing to delete.\n");
		return;
	}

	//Decrement top count
	(*head)->top--;

	slist_t *new = *head;
	*head = new->next;

	//Free memory
	free(new);

	printf("First node deleted.\n");

}


//Display the list
void sl_display_list(slist_t **head)
{
	//Return if no link exists
	if( *head == NULL )
	{
		printf("Nothing to display.\n");
		return;
	}
	else
	{
		slist_t *ptr_cur = *head;

		printf("Data:");

		//Traverse through link list
		while( ptr_cur->next != NULL )
		{
			//Display data
			printf("%d ", ptr_cur->data);

			//Move the pointer
			ptr_cur = ptr_cur->next;
			
		}//while

		//Display last data
		printf("%d\n", ptr_cur->data);
		
	}//else

}

//Display the top data
void peep(slist_t **head)
{
	//If stack is empty
	if ( (*head)->top < 0 )
	{
		printf("Stack is empty\n");
		return;
	}

	//Display top data
	printf("Top data is:%d\n", (*head)->data);


}

