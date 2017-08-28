#include<stdio.h>
#include<stdlib.h>
#include<slist.h>

slist_t *HEAD;

//Create a new node
slist_t * create_node(data_t value)
{
	slist_t *new = malloc( sizeof(slist_t) );
	new->data = value;
	new->next = NULL;
	return new;
}

//Insert a node at first of link list
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

//Insert a node at last of link list
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

//Delete the first node
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

//Delete the last node
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

//Display the list
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

//Find the link length
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


//Delete entire link list
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

//Insert node after a data
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

//Insert node before a data
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

//Find a particuler node
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

//Delete a particular node
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

//Insert data at nth position
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

//Find the mid element of link list
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

//Get nth node from last
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
	if (*head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		slist_t *cur = *head;
		slist_t *cur1, *next1, *temp;

		for (cur = *head; cur != NULL; cur = cur->next )
		{
			for (cur1 = cur, next1 = cur->next; next1 != NULL ; next1 = next1->next)
			{
				//If the repeated data is found; break the links and delete the node
				if (cur->data == next1->data)
				{
					temp = next1;
					cur1->next = next1->next;
					free(temp);
				}

				//If data is not found, move the pointer of list
				else	
				{
					cur1 = next1;
				}

				//If the link is ended, break
				if (next1->next == NULL)
				{
					break;
				}

			}//for

			//If the link is ended, break
			if (cur->next == NULL)
			{
				break;
			}

		}//for
	
		printf("Repeated items deleted\n");	

	}//else


}

//Create a looped link list
int sl_create_loop(slist_t **head)
{
	int i = 0;
	slist_t *prev = NULL;
	slist_t *new = NULL;

	//Create a link list
	for ( i = 1; i <= 10; i++ )
	{
		new = create_node( i*10 );
		new->next = prev;
		prev = new;	

	}//for

	*head = new;

	//Display the list before looping
	sl_display_list(head);

	slist_t *ptr = *head;
	i = 0;

	while ( ptr->next != NULL )
	{

		//Make loop at 5th node
		if ( i == 5 )
			prev = ptr;

		ptr = ptr->next;
		i++;

	}//while

	ptr->next = prev;

	ptr = *head;
	i = 0;

	//Display the list after looping
	while( i != 20 )
	{
		printf("%d ", ptr->data );
		ptr = ptr->next;
		i++;
	}//while

//	sl_display_list(head);


}

//Find loop in link list
int sl_find_loop(slist_t **head)
{

	if( *head == NULL )
	{
		printf("No list present\n");
	}
	else
	{
		//Allocate memory for storing address of nodes
		slist_t **link_arr = malloc( 50 * sizeof( slist_t * ) );

		slist_t *ptr = *head;
		int i, j, loop_found = 0;

		//Run the loop to find loop
		for ( i = 0; i < 20 ; i++ )
		{
			//Store address of node in array
			link_arr[i] = ptr;
	
			//Check if the address of node is present in array
			for ( j = 0; j < i; j++ )
			{
				//break if address of node is found
				if ( ptr == link_arr[j] )
				{
					printf("Loop found!!! Looping at %d\n", ptr->data );
					loop_found = 1;
					break;
				}
			
			}//for

			if ( loop_found == 1 )
				break;

			ptr = ptr->next;


		}//for


	}//else

}


//Sort Merge
void sl_sort_merge(slist_t **head1, slist_t **head2)
{
	//Assign ptrs for two lists
	slist_t *ptr1 = *head1, *ptr2 = *head2, *temp = NULL;

	//Use flags for end of list
	int flag1 = 0, flag2 = 0;

	//Run loop till ptr is valid
	while( ptr1 != NULL || ptr2 != NULL )
	{

		//If the data in 2nd list is smaller than 1st and 2nd data in 1st list, then move the current pointer in first list
		if (ptr1->data < ptr2->data && ptr1->next->data < ptr2->data)
		{
			ptr1 = ptr1->next;

		}//if

		//If the data in 2nd list is larger than 1st and smaller than 2nd data in 1st list, then insert the data of 2nd element in 1st element
		else if (ptr1->data < ptr2->data && ptr1->next->data > ptr2->data)
		{
			sl_insert_after( head1, ptr2->data, ptr1->data );
			temp = ptr2;
			ptr2 = ptr2->next;
			free(temp);
			*head2 = ptr2;
			ptr1 = ptr1->next;

		}//else if

		//if the data in 2nd element is greater than data in 1st list, move current pointer of 2nd list
		else if (ptr1->data > ptr2->data)
		{
			sl_insert_before(head1, ptr2->data, ptr1->data );
			ptr2 = ptr2->next;
		}//else if

		//Break when merging of two lists are done
		if (flag1 == 1 || flag2 == 1)
			break;

		//If 1st list is ended set flag and continue
		if (ptr1->next == NULL)
		{
			flag1 = 1;
			continue;
		}

		//If 2nd list is ended set flag and continue
		if (ptr2->next == NULL)
		{
			flag2 = 1;
			continue;
		}
		

	}//while

}

//Reverse recurrsion
void sl_reverse_recursive(slist_t **head, slist_t **head_next)
{
	slist_t *cur = *head, *next = *head_next, *next_next = NULL;

	//If it is the last node, make it head and change links
	if (!next->next)
	{
		next->next = cur;
		HEAD = next;
		return;
	}

	//If it is the first node, make its next link as NULL
	if (HEAD == *head)
	{
		cur->next = NULL;
	}

	//Change links
	next_next = next->next;
	next->next = cur;

	//Call function recursively, sending the broken links as arguments
	sl_reverse_recursive(&next, &next_next);
	
	
}
