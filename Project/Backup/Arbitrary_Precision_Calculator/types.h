#ifndef TYPES_H
#define TYPES_H

#include "dlist.h"

typedef enum
{
	failure, success
}Status;

typedef struct _apc_t
{
	char exp[1000];
	char num1[1000], num2[1000], num3[1000], num4[1000];
	int num1_len, num2_len, num3_len, num4_len;
	char op;
	int float_flag1, float_flag2;
	dlist_t *head1, *tail1, *head2, *tail2, *head3, *tail3, *head4, *tail4, *head_result_LHS, *tail_result_LHS, *head_result_RHS, *tail_result_RHS;


}APC_struct;


/*	Function Protypes	*/

//Read input from user
Status read_input(APC_struct *apc_struct);

//Split numbers and store into double link list
Status split_numbers(APC_struct *apc_struct);

//Pre Pad number with 0
Status pad_numbers(APC_struct *apc_struct);

//Add Link List
Status add_link_list(APC_struct *apc_struct);

//Subtract Link List
Status sub_link_list(APC_struct *apc_struct);


#endif
