#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash.h"

//Variable declared in main function file
extern int size;

//Create node function
slist_t * create_node(data_t value)
{
	//Allocate memory for new node
	slist_t *new = malloc(sizeof(slist_t));

	//Copy the data into node
	new->data = strdup(value);

	//Make next link as NULL
	new->next = NULL;

	//Return new node
	return new;
}

//Insert a node at last of link list
void sl_insert_last(slist_t **head, slist_t **tail, data_t value)
{
	//If list does not exist, create list and update head & tail
	if (*head == NULL)
	{
		*head = create_node(value);
		*tail = *head;
	}

	//If list exists, append the new node to last
	else
	{
		//Initialise a ptr to head
		slist_t *ptr = *head;

		//Traverse through list until last node is reached
		while (ptr->next != NULL)
		{
			ptr = ptr->next;

		}//while

		ptr->next = create_node(value);

		//Update tail
		*tail = ptr->next;

	}//else

}

//Display Single Link List
bool_hash sl_display_list(slist_t *head)
{
	//If head does not exist, return failure
	if(head == NULL)
	{
		return failure;
	}

	//Else display list
	else
	{
		slist_t *ptr_cur = head;

		printf("Data:");

		//Traverse through list and display data
		while(ptr_cur->next != NULL)
		{
			printf("%s->", ptr_cur->data);
			ptr_cur = ptr_cur->next;
			
		}//while

		//Display last data
		printf("%s\n", ptr_cur->data);
		
	}//else

}

//Search Data Single Link List
slist_t * sl_search_list(slist_t *head, data_t key)
{
	//If list does not exist, return NULL
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		slist_t *ptr_cur = head;

		//Traverse through list
		while(ptr_cur)
		{
			//Display data if key is found
			if (strcmp(ptr_cur->data, key) == 0)
			{
				return ptr_cur;
			}

			//Increment the pointer
			if (ptr_cur->next != NULL)
			{
				ptr_cur = ptr_cur->next;
			}

			//Return if list is ended
			else
			{
				return NULL;
			}

		}//while
		
	}//else

}


//Hash function
int hash_function(data_t key)
{
	int index;

	//Find the index of hash table using ASCII values
	if (*key >= 65 && *key <= 90)
	{
		index = *key - 65;
	}
	else if (*key >= 97 && *key <= 122)
	{
		index = *key - 97;
	}

	//Return calculated index 
	return index;
}

//Insert data into Hash Table
bool_hash hash_insert_data(HashStruct **hashtable, data_t key)
{
	int index;

	//Find index of hash table by calling function
	index = hash_function(key);

	if (index > size)
	{
		return failure;
	}

	//Insert the nodes into table
	sl_insert_last(&(((*hashtable) + index)->head), &(((*hashtable) + index)->tail), key);

	return success;

}

//Display Hast Table
bool_hash display_hashtable(HashStruct **hashtable)
{
	int index;
	
	//Return failure, if hash table is not present
	if (*hashtable == NULL)
	{
		return failure;

	}//if

	//Display hash table
	for (index = 0; index < size; index++)
	{
		//Call list display function
		sl_display_list(((*hashtable) + index)->head);

	}//for
	return success;

}

//Search Data
slist_t * hash_search_data(HashStruct **hashtable, data_t key)
{
	int index;
	slist_t *result;

	//Search through all rows of hash table
	for (index = 0; index < size; index++)
	{
		//Call function & Store the address of node in a pointer
		result = sl_search_list(((*hashtable) + index)->head, key);

		//If data is found, return the address of node
		if (result != NULL)
		{
			return result;

		}//if
	}//for

	//Return NULL if data is not found
	return NULL;


}

//Delete data in hashtable
bool_hash delete_data_in_hashtable(HashStruct **hashtable, data_t key)
{

	int index;

	bool_hash status;
	slist_t *ptr_cur = NULL, *ptr_prev = NULL, *temp = NULL;

	//Search through all rows of hash table
	for (index = 0; index < size; index++)
	{
		//Initialise pointers to current and previous node respectively
		ptr_cur = ((*hashtable) + index)->head;
		ptr_prev = ptr_cur;
		
		//Traverse through list till its end
		while(ptr_cur)
		{
			//Display data if key is found
			if (strcmp(ptr_cur->data, key) == 0)
			{
				//If the data to be deleted is head
				if (ptr_cur == ((*hashtable) + index)->head)
				{
					//Update head if the head node is deleted
					((*hashtable) + index)->head = ptr_cur->next;
				}

				//Update the nodes
				temp = ptr_cur;
				ptr_cur = ptr_cur->next;
				ptr_prev->next = ptr_cur;

				//Free the node
				free(temp);

				return success;
			}

			if (ptr_cur->next != NULL)
			{
				//Update pointers to traverse through the list
				ptr_prev = ptr_cur;
				ptr_cur = ptr_cur->next;
			}
			else
			{
				return failure;
			}

		}//while

	}

	return failure;


}

//Delete the hash table
bool_hash delete_hashtable(HashStruct **hashtable)
{
	int index;

	bool_hash status;
	slist_t *ptr_cur = NULL, *ptr_prev = NULL;

	//Search through all rows of hash table
	for (index = 0; index < size; index++)
	{
		//Make a pointer to point to current head
		ptr_cur = ((*hashtable) + index)->head;

		//If table contains data; delete the data, i.e., nodes
		if (ptr_cur != NULL)
		{
			//Traverse through list
			while(ptr_cur)
			{
				//Update the pointers and free the the previous node
				if (ptr_cur->next != NULL)
				{
					ptr_prev = ptr_cur;
					ptr_cur = ptr_cur->next;
					free(ptr_prev);
				}

				//Free current node and break the loop
				else
				{
					free(ptr_cur);
					break;
				}

			}//while
		}//if

	}

	return success;

}

