#include<stdio.h>
#include<stdlib.h>
#include<slist.h>

slist_t * create_node(data_t value)
{
	slist_t *new = malloc( sizeof(slist_t) );
	new->data = value;
	new->next = NULL;
	return new;
}

void sl_insert_first(slist_t **head, data_t value)
{
	if( *head == NULL )
	{
		*head = create_node(value);
	}
	else
	{
		slist_t *new = create_node(value);
		new->next = *head;
		*head = new;
	}//else
	printf("First node inserted.\n");
}

void sl_insert_last(slist_t **head, data_t value)
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

	printf("Last node inserted.\n");

}

void sl_delete_first(slist_t **head)
{
	if( *head == NULL )
	{
		printf("Nothing to delete.\n");
	}
	else
	{
		slist_t *new = *head;
		*head = new->next;

		free(new);

		printf("First node deleted.\n");
	}//else
}

void sl_delete_last(slist_t **head)
{
	if( *head == NULL )
	{
		printf("Nothing to delete.\n");
	}
	else
	{
		slist_t *ptr_cur = *head;
		slist_t *ptr_next = *head;

		ptr_next = ptr_cur->next;

		while( ptr_next->next != NULL )
		{
			ptr_cur = ptr_cur->next;			
			ptr_next = ptr_next->next;
			
		}//while

		ptr_cur->next = NULL;

		free(ptr_next);
		printf("Last node deleted.\n");

	}//else

}

void sl_display_list(slist_t **head)
{
	if( *head == NULL )
	{
		printf("Nothing to display.\n");
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
		
	}//else

}

int sl_linklen(slist_t **head)
{
	int count = 0;

	if(*head == NULL )
		return count;
	else
	{
		slist_t *ptr = *head;
		while( ptr->next != NULL )
		{
			count++;
			ptr = ptr->next;		
		}

		
		return ++count;
	}//else	


}


void sl_delete_list(slist_t **head)
{
	if( *head == NULL )
	{
		printf("Nothing to delete.\n");
	}
	else
	{
		slist_t *ptr_cur = *head;
		slist_t *ptr_prev = *head;

		while( ptr_cur != NULL )
		{
			ptr_prev = ptr_cur;
			ptr_cur = ptr_cur->next;
			free(ptr_prev);
			
		}//while

		(*head)->data = 0;		
		(*head)->next = NULL;

		printf("All nodes deleted.\n");

	}//else

}

void sl_insert_after(slist_t **head, data_t value, data_t element)
{
	slist_t *ptr = *head;
	int flag_data_found = 0;

	while(ptr->next != NULL )
	{
		if( ptr->data == element )
		{
			slist_t *new = create_node(value);
			new->next = ptr->next;
			ptr->next = new;
			flag_data_found = 1;
			break;
		}//if

		ptr = ptr->next;
	}//while

	if( flag_data_found == 0)
		printf("Element does not exist\n");
	

}

void sl_insert_before(slist_t **head, data_t value, data_t element)
{
	slist_t *ptr = *head;
	slist_t *prev = *head;
	int flag_data_found = 0;

	if( ptr->data == element )
	{
		sl_insert_first(head, value);
		return;
	}

	while( ptr->next != NULL )
	{
		if( ptr->data == element )
		{
			slist_t *new = create_node(value);
			new->next = ptr;
			prev->next = new;
			flag_data_found = 1;
			break;
		}//if

		prev = ptr;
		ptr = ptr->next;

	}//while

	if( ptr->data == element )
	{
		slist_t *new = create_node(value);
		new->next = ptr;
		prev->next = new;
		flag_data_found = 1;
	}//if


	if( flag_data_found == 0)
		printf("Element does not exist\n");


}

slist_t *sl_find_node(slist_t **head, data_t element)
{
	if( *head == NULL )
		printf("No list present\n");

	else
	{
		slist_t *ptr = *head;

		while( ptr->next != NULL )
		{
			if( ptr->data == element )
			{
				return ptr;
			}//if

		ptr = ptr->next;

		}//while
		
		return NULL ;
	}//else
}

int sl_delete_element(slist_t **head, data_t element)
{
	if( *head == NULL )
		printf("No list present\n");

	else
	{
		slist_t *ptr = *head, *prev = *head;
		int flag = 0;

		while( ptr )
		{
			if( ptr->data == element )
			{
				flag = 1;

				if ( ptr == *head )
				{
					*head = ptr->next;
					break;
				}
				if ( ptr->next == NULL )
				{
					prev->next = NULL;
					break;
				}
				else
				{
					prev->next = ptr->next;
					break;
				}//else
			}//if

			prev = ptr;
			ptr = ptr->next;	

		}//while
		
		if( flag == 1 )
		{
			return 1;
		}//if
		else if( flag == 0 )
		{
//			printf("Element not found in the list.\n");
			return 0;
		}


	}//else

}

void sl_insert_nth(slist_t **head, data_t value, int n)
{
	if( *head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		if( sl_linklen(head) < n )
		{
			printf("There are only %d elements in the link. Please enter a lesser value.\n", sl_linklen(head));
		}
		else if( n == 1 )
		{
			sl_insert_first(head, value);
		}
		else
		{
			slist_t *ptr = *head, *prev = *head;
			int count = 1;
			while( count != n)
			{
				prev = ptr;
				ptr = ptr->next;
				count++;
			}

			slist_t *new = create_node(value);
			prev->next = new;
			new->next = ptr;
		}

	}//else
}


slist_t *sl_find_mid_element(slist_t **head)
{
	if( *head == NULL )
		printf("No list present\n");

	else
	{
		int link_len = sl_linklen(head);
		int mid_element, index = 1;
		slist_t *ptr = *head;

		if( link_len % 2 == 0 )
			mid_element  = link_len / 2;
		else
			mid_element = ( link_len + 1 ) / 2;

		
		while( index != mid_element )
		{
			ptr = ptr->next;
			index++;
		}

		printf("Mid element is %d\n", ptr->data);
//		return ptr;
	
	}//else

}

slist_t *sl_get_nth_from_last(slist_t **head, int n)
{
	if( *head == NULL )
		printf("No list present\n");

	else
	{
		int link_len = sl_linklen(head);
		int count = 0, index = 0;
		slist_t *ptr = *head, *pre = *head;
	
		if( n > link_len )
		{
			printf("There are only %d elements in the link. Please enter a lesser value.\n", sl_linklen(head));
		}
		else
		{		
			count = (n == 1) ? link_len : link_len - n;
			printf("count:%d\n", count);
			while( index != count )
			{
				pre = ptr;
				ptr = ptr->next;
				index++;
			}//while


			printf("index:%d\n", index);
			if( index == count )
			{
				if( n > 1 )
					printf("Element at %dth position from last is %d\n", n, ptr->data);
				else if( n == 1)
					printf("Element at %dth position from last is %d\n", n, pre->data);
			}//if
			
		}//else

	}//else
}

//Sort the given link list
void sl_sort_list(slist_t **head)
{
	if( *head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		int i;

		for( i = 0; i < sl_linklen(head); i++ )
		{
			slist_t *cur = *head, *next = cur->next;

			while( cur->next != NULL )
			{
				if( cur->data > next->data)
				{
					int temp;
					temp = next->data;
					next->data = cur->data;
					cur->data = temp;
				}//if

				cur = next;
				next = next->next;

			}//while
		}//for

		printf("List is sorted.\n");
		sl_display_list(head);

	}//else

}

//Reverse link list
void sl_reverse_iterative(slist_t **head)
{
	if( *head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		int linklen = sl_linklen(head);
		int i = 0;

		data_t *arr = malloc( linklen * sizeof( data_t) );
		slist_t *cur = *head;

		while( cur->next != NULL )
		{
			arr[i] = cur->data;
			cur = cur->next;
			i++;

		}//while

		arr[i] = cur->data;

		cur = *head;
		i = linklen - 1;

		while( i >= 0 )
		{
			cur->data = arr[i];
			cur = cur->next;
			i--;

		}//while

		printf("List is reversed.\n");
		sl_display_list(head);
	
		free(arr);

	}//else

}

void sl_remove_repeated(slist_t **head)
{
	if( *head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		int linklen = sl_linklen(head);
		int i = 0, j, flag = 0;

		data_t *arr = malloc( linklen * sizeof( data_t) );

		slist_t *cur = *head;

		while( cur->next != NULL )
		{
			arr[i] = cur->data;
			cur = cur->next;
			i++;

		}//while

		arr[i] = cur->data;

		for(cur = *head ; cur->next != NULL;  )
		{
			for( j = 0; j < linklen; j++ )
			{

				if( cur->data == arr[j] && flag == 1)
				{
					sl_delete_element( &(cur->next), arr[j] );
					arr[j] = -1;
					flag = 0;
					cur = *head;
					goto start;

				}//if
				if( cur->data == arr[j] )
				{
					flag = 1;
				}//if

			}//for


			cur = cur->next;
start:			continue;

		}//for

		printf("Repeated elements deleted.\n");
	
	}//else


}

//Insert element sort 
bool_slist insert_sort(slist_t **head, data_t data)
{
	if ( *head == NULL )
	{
		return failure;
	}
	else
	{
		slist_t *ptr = *head;

		while( ptr->next != NULL )
		{
			
			if ( data < ptr->data )
			{
				sl_insert_before( head, data, ptr->data);
				return success;
			}//if

			ptr = ptr->next;

		}//while

		sl_insert_last( head, data);

		return success;

	}//else

}

//Find mid point using one iteration
data_t sl_find_midpoint_single_iter(slist_t **head)
{
	if ( *head == NULL )
	{
		return failure;
	}
	else
	{
		if ( (*head)->next->next == NULL )
			return (*head)->data;

		slist_t *cur = *head, *next = (*head)->next->next;

		while ( 1 )
		{
			if ( next->next == NULL )
				return cur->next->data;
			else
			{
				cur = cur->next;

				next = next->next;

				if ( next->next == NULL )
					return cur->data;
				else
					next = next->next;

			}//else
			

		}//while
	


	}//else

}



