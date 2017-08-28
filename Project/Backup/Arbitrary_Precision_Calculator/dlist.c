#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "dlist.h"

//Display zeros
bool_t display_zeros(data_t num)
{
	char cdata[15];
	int len_diff, cdata_len, i;

	sprintf( cdata, "%d", num );

	cdata_len = strlen( cdata );

	if ( cdata_len < 9 )
	{
		len_diff = 9 - cdata_len;

		for ( i = 0; i < len_diff; i++ )
		{
			cdata[i] = '0';
		}
		cdata[i] = '\0';

	}//if

	printf("%s", cdata );
	printf("%d", num );

	return success_dl;

}


//Display double link list
bool_t dl_display_list(dlist_t **head)
{
	char cdata[15];

	if ( *head == NULL )
		return failure_dl;
	else
	{
		dlist_t *ptr = *head;

//		printf("Data:");
		while( ptr->next != NULL )
		{
			sprintf( cdata, "%d", ptr->data );

			if ( strlen(cdata) < 9 )
				display_zeros(ptr->data);
			else
				printf("%d", ptr->data);

			ptr = ptr->next;

		}//while

		printf("%d", ptr->data);

	}//else

}

//Insert data at last of link list
bool_t dl_insert_last(dlist_t **head, dlist_t **tail, data_t data)
{
	dlist_t *new = malloc( sizeof(dlist_t) );

	if ( new == NULL )
		return failure_dl;

	new->prev = new->next = NULL;
	new->data = data;

	if( *head == NULL )
		*head = *tail = new;
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
		return success_dl;
	}//else

}

//Add Link List
Status add_link_list(APC_struct *apc_struct)
{
	dlist_t *ptr1 = apc_struct->head1, *ptr2 = apc_struct->head2, *ptr3_result_LHS = apc_struct->head_result_LHS;
	dlist_t *ptr3 = apc_struct->head3, *ptr4 = apc_struct->head4, *ptr3_result_RHS = apc_struct->head_result_RHS;
	data_t result;

/********************************************************************************************************************/
	while( ptr1 != NULL && ptr2 != NULL )
	{
		result = ptr1->data + ptr2->data;

		dl_insert_last( &apc_struct->head_result_LHS, &apc_struct->tail_result_LHS, result);

		if ( ptr1->next == NULL )
			break;
		else
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;

		}//else

	}//while
/********************************************************************************************************************/


/********************************************************************************************************************/

	while( ptr3 != NULL && ptr4 != NULL )
	{
		result = ptr3->data + ptr4->data;

		dl_insert_last( &apc_struct->head_result_RHS, &apc_struct->tail_result_RHS, result);

		if ( ptr3->next == NULL || ptr4->next == NULL)
			break;
		else
		{
			ptr3 = ptr3->next;
			ptr4 = ptr4->next;

		}//else

	}//while



/********************************************************************************************************************/
}

//Sub Link List
Status sub_link_list(APC_struct *apc_struct)
{
	dlist_t *ptr1 = apc_struct->head1, *ptr2 = apc_struct->head2, *ptr3_result_LHS = apc_struct->head_result_LHS;
	dlist_t *ptr3 = apc_struct->head3, *ptr4 = apc_struct->head4, *ptr3_result_RHS = apc_struct->head_result_RHS;

	data_t result_LHS, result_RHS;

	char result_char_LHS[1000] = "", result_char_RHS[1000] = "", temp_char[1000], *ptr;
	int sign_flag = 0;

/********************************************************************************************************************/
	while( ptr1 != NULL && ptr2 != NULL )
	{
		result_LHS = ptr1->data - ptr2->data;
		
		if ( result_LHS < 0 )
			sign_flag = 1;

		sprintf(temp_char, "%d", result_LHS);
		strcat( result_char_LHS, temp_char);

		dl_insert_last( &apc_struct->head_result_LHS, &apc_struct->tail_result_LHS, result_LHS);

		if ( ptr1->next == NULL )
			break;
		else
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;

		}//else

	}//while

	if ( sign_flag == 1)
	{
		printf("-");
		ptr = strtok(result_char_LHS, "-");
		while ( ptr != NULL )
		{
			printf("%s ", ptr);
			ptr = strtok(NULL, "-" );
		}

	}//if

/********************************************************************************************************************/


/********************************************************************************************************************/
	while( ptr3 != NULL && ptr4 != NULL )
	{
		result_RHS = ptr3->data - ptr4->data;
		
		if ( result_RHS < 0)
			sign_flag = 1;

		sprintf(temp_char, "%d", result_RHS);
		strcat( result_char_RHS, temp_char);

		dl_insert_last( &apc_struct->head_result_RHS, &apc_struct->tail_result_RHS, result_RHS);

		if ( ptr1->next == NULL )
			break;
		else
		{
			ptr3 = ptr3->next;
			ptr4 = ptr4->next;

		}//else

	}//while

	if ( sign_flag == 1)
	{
		printf("-");
		ptr = strtok(result_char_RHS, "-");
		while ( ptr != NULL )
		{
			printf("%s ", ptr);
			ptr = strtok(NULL, "-" );
		}

	}//if

/********************************************************************************************************************/

}







