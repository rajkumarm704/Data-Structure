#ifndef TYPES_H
#define TYPES_H

typedef enum
{
	failure, success
}Status;

typedef int data_t;

//Double link list structure
typedef struct _dlist_t
{
	struct _dlist_t *prev;
	struct _dlist_t *next;
	data_t data;

}dlist_t;

typedef enum 
{
	failure_dl, success_dl
}bool_t;

//APC structure
typedef struct _apc_t
{
	char exp[1000];
	char num1[1000], num2[1000], num3[1000], num4[1000];
	int num1_len, num2_len, num3_len, num4_len;
	char op;
	int float_flag1, float_flag2;
	dlist_t *head1, *tail1, *head2, *tail2, *head3, *tail3, *head4, *tail4, *head_result_LHS, *tail_result_LHS, *head_result_RHS, *tail_result_RHS;
	int carry;


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

//Display double link list
bool_t dl_display_list(dlist_t **head, APC_struct *apc_struct);

//Insert data at last of link list
bool_t dl_insert_last(dlist_t **head, dlist_t **tail, data_t data);

//Insert data at last of link list
bool_t dl_insert_first(dlist_t **head, dlist_t **tail, data_t data);



#endif
