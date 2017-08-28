#include<stdio.h>
#include<stdlib.h>
#include<array_stack.h>

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}

int main()
{
	system("clear");

	//user option
	int option;

	//status variable
	bool_arr_stack status;

	//stack variable
	array_stack_t s;	

	//create stack
	status = create_array_stack(&s);

	if ( status == mem_alloc_success )
		printf("Stack has been created successfully.\n");
	else if ( status == mem_alloc_failure )
		printf("Stack was created. Memory was full.\n");


	data_t data;

	while(1)
	{
		printf("\nChoose an operation from below:\n"
			"1.	 push\n"
			"2.	 pop\n"
			"3.	 peep\n"
			"4.	 peek\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n\n");


		switch(option)
		{
			case 1:
				read_data(&data);
				status = push_array( &s, data );

				if ( status == success )
					printf("Data succesfully pushed onto the stack.\n");
				else if ( status == stack_does_not_exist_failure )
					printf("Stack does not exist.\n");
				else if ( status == max_size_failure )
					printf("Maximum size of stack has been reached!!! No more data can be pushed onto the stack.\n");

				break;
			case 2:
				status = pop_array( &s );

				if ( status == success )
					printf("Stack sucessfully popped.\n");
				else if ( status == stack_does_not_exist_failure )
					printf("Stack does not exist.\n");
				else if ( status == stack_empty_failure )
					printf("All the data has been popped from the stack.\n");

				break;

			case 4:
				status = peep_array(&s);

				if ( status == success )
					printf("Stack was shown sucessfully.\n");
				else if ( status == stack_does_not_exist_failure )
					printf("Stack does not exist.\n");
				else if ( status == stack_empty_failure )
					printf("Nothing to display. All the data has been popped from the stack.\n");

				break;

			case 100:	
				printf("The program will exit now...\n");
				return 0;


			default:
				printf("Wrong option selected...Please try again...\n");

		}//switch

	}//while
}
