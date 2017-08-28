#include<stdio.h>
#include<stdlib.h>
#include<circular_queue.h>

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}

int main()
{

	system("clear");

	int option;
	data_t data;

	queue_c q;
	bool_queue_c status;

	status = create_queue( &q );

	if ( status == queue_created_success )
		printf("Queue of size %ld was created successfully.\n", q.size );
	else if ( status == queue_not_created_failure )
		printf("Queue creation failed. Memory full.\n");


	while(1)
	{
		printf("\nChoose an operation from below:\n"
			"1.	 Enqueue\n"
			"2.	 Dequeue\n"
			"3.	 Print Queue\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n\n");


		switch(option)
		{
			case 1:
				read_data(&data);
				status = enqueue_c( &q, data );

				if ( status == success )
					printf("Data succesfully entered in to the circular queue.\n");
				else if ( status == queue_full_failure )
					printf("Maximum size of queue has been reached!!! No more data can be entered in to the queue.\n");

				break;

			case 2:
				status = dequeue_c( &q );

				if ( status == dequeue_success )
					printf("Data succesfully removed from circular queue.\n");
				else if ( status == queue_full_failure )
					printf("Maximum size of queue has been reached!!! No more data can be entered in to the queue.\n");

				break;



			case 3:
				status = display_queue_c(&q);
				if ( status == success )
					printf("Queue displayed sucessfully.\n");

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
