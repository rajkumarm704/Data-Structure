#include<stdio.h>
#include<stdlib.h>

#include"types.h"

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}


int main()
{

	system("clear");

	int option ;
	data_t data;
	slist_t *head = NULL;
	bool_queue_CLL status;

	while(1)
	{
		printf("\n\nChoose an operation from below:\n"
			"1.	 Enqueue\n"
			"2.	 Dequeue\n"
			"3.	 Display Queue\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n\n");
		switch(option)
		{
			//Enqueue
			case 1:	
				//Read input from user
				read_data(&data);

				//Enqueue
				status = sl_insert_last(&head, data);
				
				//Display sthe status of funtions
				if ( status == success )
				{
					printf("Data enqueue successfull.\n");
				}
				else if ( status == failure )
				{
					printf("Data enqueue unsuccessfull.\n");
				}

				break;

			//Dequeue
			case 2:
				//Dequeue
				status = sl_delete_first(&head);

				//Display sthe status of funtions
				if ( status == success )
				{
					printf("Data Dequeue successfull.\n");
				}
				else if ( status == queue_empty_failure )
				{
					printf("Data Dequeue unsuccessfull. The queue is empty\n");
				}


				break;

			case 3:
				status = sl_display_list(&head);

				//Display sthe status of funtions
				if ( status == success )
				{
					printf("Data displayed successfully.\n");
				}
				else if ( status == queue_empty_failure )
				{
					printf("Nothing to display. The queue is empty\n");
				}

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
