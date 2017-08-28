#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "dlist.h"

Status read_input(APC_struct *apc_struct)
{
	int i, j;

	//ptr for strtok function
	char *ptr, num_copy[1000];


	printf("Enter the expression:" ), scanf("%[^\n]", apc_struct->exp );

	printf("\n\nThe expression is:%s\n", apc_struct->exp );

	//Separate the numbers from expression
	for ( i = 0; apc_struct->exp[i] != '\0'; i++ )
	{
		if ( apc_struct->exp[i] >= 48 && apc_struct->exp[i] <= 57 || apc_struct->exp[i] == '.')
			apc_struct->num1[i] = apc_struct->exp[i];
		else
			break;

	}//for

	//Store the operation
	apc_struct->op = apc_struct->exp[i];

	apc_struct->num1[i] = '\0';

	//Find if the numbers are floating point or not
	if ( strchr(apc_struct->num1, '.') != NULL )
	{
		//Set float flag 1
		apc_struct->float_flag1 = 1;

		//Make a copy of number
		strcpy( num_copy, apc_struct->num1 );

		//Separate LHS of decimal point
		ptr = strtok( num_copy, "." );
		strcpy( apc_struct->num1, ptr );		

		//Separate RHS of decimal point
		ptr = strtok(NULL, "." );
		strcpy( apc_struct->num3, ptr);

//		printf("Number 1:%s.%s\n", apc_struct->num1, apc_struct->num3);

	}//if
	else
	{
//		printf("\n\nNumber 1:%s\n", apc_struct->num1);
		apc_struct->num3[0] = '\0';
	}//else

	for ( j = i+1, i = 0; apc_struct->exp[i] != '\0'; i++, j++ )
	{
		if ( apc_struct->exp[j] >= 48 && apc_struct->exp[j] <= 57 || apc_struct->exp[j] == '.')
			apc_struct->num2[i] = apc_struct->exp[j];
		else
			break;

	}//for

	apc_struct->num2[i] = '\0';

	//Find if the numbers are floating point or not
	if ( strchr(apc_struct->num2, '.') != NULL )
	{
		//Set float flag 2
		apc_struct->float_flag2 = 1;

		//Make a copy of number
		strcpy( num_copy, apc_struct->num2 );

		//Separate LHS of decimal point
		ptr = strtok( num_copy, "." );
		strcpy( apc_struct->num2, ptr );		

		//Separate RHS of decimal point
		ptr = strtok(NULL, "." );
		strcpy( apc_struct->num4, ptr);
		
//		printf("Number 2:%s.%s\n", apc_struct->num2, apc_struct->num4);

	}//if
	else
	{
//		printf("Number 2:%s\n", apc_struct->num2);
		apc_struct->num4[0] = '\0';
	}

	//LHS of decimal point
	apc_struct->num1_len = strlen(apc_struct->num1);
	apc_struct->num2_len = strlen(apc_struct->num2);

	//RHS of decimal point
	apc_struct->num3_len = strlen(apc_struct->num3);
	apc_struct->num4_len = strlen(apc_struct->num4);

	if (  apc_struct->num1 != NULL && apc_struct->num2 != NULL )
		return success;
	else
		return failure;

}

//Pre Pad number with 0
Status pad_numbers(APC_struct *apc_struct)
{
	int i, len_diff;
	char temp_num[1000];

	//LHS of decimal point
	if ( apc_struct->num1_len > apc_struct->num2_len )
	{
		len_diff = apc_struct->num1_len - apc_struct->num2_len;

		for ( i = 0; i < len_diff; i++ )
		{
			temp_num[i] = '0';
		}
		temp_num[i] = '\0';
		strcat( temp_num, apc_struct->num2 );
		strcpy( apc_struct->num2, temp_num );

	}//if
	else if ( apc_struct->num2_len > apc_struct->num1_len )
	{
		len_diff = apc_struct->num2_len - apc_struct->num1_len;

		for ( i = 0; i < len_diff; i++ )
		{
			temp_num[i] = '0';
		}
		temp_num[i] = '\0';
		strcat( temp_num, apc_struct->num1 );
		strcpy( apc_struct->num1, temp_num );

	}//if

	if ( apc_struct->float_flag1 == 1 || apc_struct->float_flag2 == 1 )
	{
		printf("\n\nNumbers are:\n%s.%s\n", apc_struct->num1, apc_struct->num3);
		printf("Numbers are:\n%s.%s\n\n", apc_struct->num2, apc_struct->num4);
	}
	else if ( apc_struct->float_flag1 == 0 || apc_struct->float_flag2 == 0 )
	{
		printf("\n\nNumbers are:\n%s\n", apc_struct->num1 );
		printf("Numbers are:\n%s\n\n", apc_struct->num2 );
	}

}

//Split numbers and store into double link list
Status split_numbers(APC_struct *apc_struct)
{
	pad_numbers(apc_struct);

	int i, count, data;
	char temp_data[10];

	//Create double link list for LHS of number 1
/************************************************************************************************************/
	for ( i = 0, count = 0; apc_struct->num1[i] != '\0'; i++, count++ )
	{
		temp_data[count] = apc_struct->num1[i];		

		if ( count == 8 )
		{
			temp_data[count+1] = '\0';
			data = atoi(temp_data);
			dl_insert_last(&apc_struct->head1, &apc_struct->tail1, data);
			count = -1;
		}//if

	}//for
	
	temp_data[count] = '\0';

	if ( strlen(temp_data) > 0 )
	{
		temp_data[count] = '\0';
		data = atoi(temp_data);
		dl_insert_last(&apc_struct->head1, &apc_struct->tail1, data);

	}//if
/************************************************************************************************************/


	//Create double link list for LHS of number 2
/************************************************************************************************************/
	for ( i = 0, count = 0; apc_struct->num2[i] != '\0'; i++, count++ )
	{
		temp_data[count] = apc_struct->num2[i];		

		if ( count == 8 )
		{
			temp_data[count+1] = '\0';
			data = atoi(temp_data);
			dl_insert_last(&apc_struct->head2, &apc_struct->tail2, data);
			count = -1;
		}//if

	}//for
	
	temp_data[count] = '\0';

	if ( strlen(temp_data) > 0 )
	{
		temp_data[count] = '\0';
		data = atoi(temp_data);
		dl_insert_last(&apc_struct->head2, &apc_struct->tail2, data);

	}//if
/************************************************************************************************************/



	//Create double link list for RHS of number 1
/************************************************************************************************************/
	for ( i = 0, count = 0; apc_struct->num3[i] != '\0'; i++, count++ )
	{
		temp_data[count] = apc_struct->num3[i];		

		if ( count == 8 )
		{
			temp_data[count+1] = '\0';
			data = atoi(temp_data);
			dl_insert_last(&apc_struct->head3, &apc_struct->tail3, data);
			count = -1;
		}//if

	}//for
	
	temp_data[count] = '\0';

	if ( strlen(temp_data) > 0 )
	{
		temp_data[count] = '\0';
		data = atoi(temp_data);
		dl_insert_last(&apc_struct->head3, &apc_struct->tail3, data);

	}//if
/************************************************************************************************************/


	//Create double link list for RHS of number 2
/************************************************************************************************************/
	for ( i = 0, count = 0; apc_struct->num4[i] != '\0'; i++, count++ )
	{
		temp_data[count] = apc_struct->num4[i];		

		if ( count == 8 )
		{
			temp_data[count+1] = '\0';
			data = atoi(temp_data);
			dl_insert_last(&apc_struct->head4, &apc_struct->tail4, data);
			count = -1;
		}//if

	}//for
	
	temp_data[count] = '\0';

	if ( strlen(temp_data) > 0 )
	{
		temp_data[count] = '\0';
		data = atoi(temp_data);
		dl_insert_last(&apc_struct->head4, &apc_struct->tail4, data);

	}//if
/************************************************************************************************************/

	
	printf("\n\n");

/*	//Display LHS of number
	dl_display_list( &apc_struct->head1 );
	dl_display_list( &apc_struct->head2 );

	//Display RHS of number
	dl_display_list( &apc_struct->head3 );
	dl_display_list( &apc_struct->head4 );
*/
	if ( apc_struct->head1 != NULL && apc_struct->head2 != NULL && apc_struct->head3 != NULL && apc_struct->head4 != NULL )
		return success;
	else
		return failure;


}






