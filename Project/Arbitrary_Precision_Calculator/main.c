#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "types.h"

int main()
{

	system("clear");

	APC_struct apc_struct;
	apc_struct.float_flag1 = 0;
	apc_struct.float_flag2 = 0;
	apc_struct.carry = 0;

	Status status;

	//Link list for LHS of number 1
	apc_struct.head1 = NULL;
	apc_struct.tail1 = NULL;

	//Link list for LHS of number 2
	apc_struct.head2 = NULL;
	apc_struct.tail2 = NULL;

	//Link list for RHS of number 1
	apc_struct.head3 = NULL;
	apc_struct.tail3 = NULL;

	//Link list for RHS of number 2
	apc_struct.head4 = NULL;
	apc_struct.tail4 = NULL;

	//Link list for LHS result
	apc_struct.head_result_LHS = NULL;
	apc_struct.tail_result_LHS = NULL;

	//Link list for RHS result
	apc_struct.head_result_RHS = NULL;
	apc_struct.tail_result_RHS = NULL;

	//Read User Input
	status = read_input ( &apc_struct );

/*	if ( status == success )
		printf("The expression was read and numbers were separated successfully\n\n");
	else if ( status == failure )
		printf("There was a problem in reading numbers. Please try again...\n\n");
*/

	//Split numbers and store into double link list
	status = split_numbers ( &apc_struct );

/*	if ( status == success )
		printf("\n\nLink list created successfully\n\n");
	else if ( status == failure )
		printf("\n\nThere was a problem in link list creation\n\n");
*/

	//Perform Operation
	printf("Operation is:%c\n\n", apc_struct.op);

	printf("The result is:");

	switch(apc_struct.op)
	{
		case '+':
			status = add_link_list( &apc_struct );
			apc_struct.float_flag1 = 0, apc_struct.float_flag2 = 0;
			dl_display_list( &apc_struct.head_result_LHS, &apc_struct );

			apc_struct.float_flag1 = 1, apc_struct.float_flag2 = 1;
//			if ( apc_struct.float_flag1 == 1 || apc_struct.float_flag2 == 1 )
//			{
				printf(".");
				dl_display_list( &apc_struct.head_result_RHS, &apc_struct );
//			}
			break;
	
		case '-':
			status = sub_link_list( &apc_struct );
			break;
	}

	printf("\n\n");

	return 0;
}


