#include<stdio.h>
#include<stdlib.h>

#include"linklist_stack.h"

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}


int main()
{

	system("clear");


	slist_t *head = NULL;

	int option;
	data_t data;


	//Run an infinite loop
	while(1)
	{
		printf("\n\nChoose an operation from below:\n"
			"1.	 Push\n"
			"2.	 Pop\n"
			"3.	 Peep\n"
			"4.	 Peek\n"
			"100.	 Exit\n"
			"Enter your choice: ");

		//Prompt user for Option
		scanf("%d", &option),printf("\n");

		//Perform operation according to user
		switch(option)
		{
			//Push the data into stack
			case 1:
				//Read data from user
				read_data(&data);

				//Call push function
				sl_insert_first(&head, data);

				break;

			//Pop the data from stack
			case 2:
				//Call push function
				sl_delete_first(&head);

				break;

			case 3:
				//Display all data
				sl_display_list(&head);

				break;

			case 4:
				//Display the top data
				peep(&head);

				break;

			case 100:	
				printf("The program will exit now...\n");
				return 0;

			default:
				printf("Wrong option selected...Please try again...\n");

		}//switch

	}//while



	return 0;
}
