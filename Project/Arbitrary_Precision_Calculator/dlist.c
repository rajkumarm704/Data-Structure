#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

//Display zeros
bool_t display_zeros(data_t num, APC_struct *apc_struct)
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

	if ( apc_struct->float_flag1 == 0 || apc_struct->float_flag2 == 0 )
	{
		printf("%s", cdata );
		printf("%d ", num );
	}
	else if ( (apc_struct->float_flag1 == 1 || apc_struct->float_flag2 == 1) && apc_struct->op == '-' )
	{
		printf("%d", num );
		printf("%s ", cdata );
	}
	else if ( apc_struct->float_flag1 == 1 || apc_struct->float_flag2 == 1 )
	{
		printf("%d", num );
		printf("%s ", cdata );
	}

	return success_dl;

}


//Display double link list
bool_t dl_display_list(dlist_t **head, APC_struct *apc_struct)
{
	char cdata[15];

	int len_diff, cdata_len, i;

	sprintf( cdata, "%d", (*head)->data );

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


	if ( *head == NULL )
		return failure_dl;
	else
	{
		dlist_t *ptr = *head;

		while( ptr )
		{

			if ( ptr == apc_struct->head_result_LHS && apc_struct->op == '-' )
			{
				printf("%d ", ptr->data );

				if ( ptr->next != NULL )
					ptr = ptr->next;
				else
					break;

			}
			else if ( ptr == *head && apc_struct->op == '-' )
			{
				printf("%s", cdata );
				printf("%d ", ptr->data );

				if ( ptr->next != NULL )
					ptr = ptr->next;
				else
					break;

			}
			else if ( ptr == *head )
			{
				printf("%d ", ptr->data);

					if ( ptr->next != NULL )
					ptr = ptr->next;
				else
					break;

				continue;
			}

			sprintf( cdata, "%d", ptr->data );

			if ( strlen(cdata) < 9 )
				display_zeros(ptr->data, apc_struct);
			else
				printf("%d ", ptr->data);

			if ( ptr->next != NULL )
				ptr = ptr->next;
			else
				break;

		}//while

//		printf("%d", ptr->data);

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

//Insert data at last of link list
bool_t dl_insert_first(dlist_t **head, dlist_t **tail, data_t data)
{
	dlist_t *new = malloc( sizeof(dlist_t) );

	if ( new == NULL )
		return failure;

	new->prev = new->next = NULL;
	new->data = data;

	if( *head == NULL )
	{
//		printf("first node created\n");
		*head = *tail = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;

	}//else

	return success;
}


//Add Link List
Status add_link_list(APC_struct *apc_struct)
{
	dlist_t *ptr1 = apc_struct->tail1, *ptr2 = apc_struct->tail2;
	dlist_t *ptr3 = apc_struct->tail3, *ptr4 = apc_struct->tail4;
	data_t result;
	int last_flag = 0;

	printf("\n");

//Adding RHS of decimal point
/********************************************************************************************************************/

	while( ptr3 != NULL && ptr4 != NULL )
	{
		result = ptr3->data + ptr4->data;

		if ( result > 999999999 )
		{
			result = result % 1000000000 ;
			apc_struct->carry = 1;
		}
		else
			apc_struct->carry = 0;

		dl_insert_first( &apc_struct->head_result_RHS, &apc_struct->tail_result_RHS, result);

		if ( ptr3->prev == NULL || ptr4->prev == NULL)
			break;
		else
		{
			ptr3 = ptr3->prev;
			ptr4 = ptr4->prev;

		}//else

	}//while



/********************************************************************************************************************/

//Adding LHS of decimal point
/********************************************************************************************************************/
	while( ptr1 != NULL && ptr2 != NULL )
	{
		result = ptr1->data + ptr2->data + apc_struct->carry;

		if ( result > 999999999 )
		{
			result = result % 1000000000 ;
			apc_struct->carry = 1;
		}
		else
		{
			apc_struct->carry = 0;
		}
		
		dl_insert_first( &apc_struct->head_result_LHS, &apc_struct->tail_result_LHS, result);


		if ( ( ptr1->prev == NULL || ptr2->prev == NULL ) && apc_struct->carry == 1 )
		{
			dl_insert_first( &apc_struct->head_result_LHS, &apc_struct->tail_result_LHS, 1);
		}

		if ( ptr1->prev == NULL || ptr2->prev == NULL )
		{
			break;
		}
		else
		{
			ptr1 = ptr1->prev;
			ptr2 = ptr2->prev;

		}//else

	}//while
/********************************************************************************************************************/



}

//Sub Link List
Status sub_link_list(APC_struct *apc_struct)
{

	dlist_t *ptr1 = NULL, *ptr2 = NULL;
	dlist_t *ptr3 = NULL, *ptr4 = NULL;


	if ( apc_struct->head1->data > apc_struct->head2->data )
	{
		ptr1 = apc_struct->tail1, ptr2 = apc_struct->tail2;
		ptr3 = apc_struct->tail3, ptr4 = apc_struct->tail4;
	}
	else if ( apc_struct->head2->data > apc_struct->head1->data )
	{
		printf("-");
		ptr1 = apc_struct->tail2, ptr2 = apc_struct->tail1;
		ptr3 = apc_struct->tail4, ptr4 = apc_struct->tail3;
	}

	data_t result_LHS, result_RHS;


//Subtracting RHS of decimal point
/********************************************************************************************************************/
	while( ptr3 != NULL && ptr4 != NULL )
	{
		result_RHS = ptr3->data - ptr4->data;
		
		dl_insert_first( &apc_struct->head_result_RHS, &apc_struct->tail_result_RHS, result_RHS);

		if ( ptr3->prev == NULL || ptr4->prev == NULL )
			break;
		else
		{
			ptr3 = ptr3->prev;
			ptr4 = ptr4->prev;

		}//else

	}//while

/********************************************************************************************************************/


//Subtracting LHS of decimal point
/********************************************************************************************************************/
	while( ptr1 != NULL && ptr2 != NULL )
	{
		result_LHS = ptr1->data - ptr2->data;


		dl_insert_first( &apc_struct->head_result_LHS, &apc_struct->tail_result_LHS, result_LHS);

		if ( ptr1->prev == NULL || ptr2->prev == NULL)
			break;
		else
		{
			ptr1 = ptr1->prev;
			ptr2 = ptr2->prev;

		}//else

	}//while

/********************************************************************************************************************/


//Displaying result

	dl_display_list( &apc_struct->head_result_LHS, apc_struct );
	printf(".");
	dl_display_list( &apc_struct->head_result_RHS, apc_struct );



}







