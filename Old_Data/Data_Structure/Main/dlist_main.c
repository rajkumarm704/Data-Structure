#include<stdio.h>
#include<stdlib.h>
#include<dlist.h>

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}

void read_element(data_t *element)
{
	printf("Enter element:"), scanf("%d", element);
}

int main()
{

	system("clear");

	dlist_t *head = NULL;
	dlist_t *tail = NULL;
	
	bool_t status;
	
	int option;
	data_t data, element;

	

	while(1)
	{
		printf("\n\nChoose an operation from below:\n"
			"1.	 display_list\n"
			"2.	 insert_first\n"
			"3.	 insert_last\n"
			"4.	 delete_first\n"
			"5.	 delete_last\n"
			"6.	 Link length\n"
			"7.	 Insert After\n"
			"8.	 Insert Before\n"
			"9.	 Delete Element\n"
			"10.	 Delete list\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n");
		switch(option)
		{
			case 1:
				//Invoke function to display list
				status = dl_display_list(&head);

				if( status == success )
					printf("List is displayed.\n");
				else if( status == failure )
					printf("List does not exist.\n");

				break;


			case 2:	
				read_data(&data);
				status = dl_insert_first(&head, &tail, data);
		
				if( status == success )
					printf("Data inserted.\n");
				else if( status == failure )
					printf("Data not inserted.\n");

				break;


			case 3:	
				read_data(&data);
				status = dl_insert_last(&head, &tail, data);
		
				if( status == success )
					printf("Data inserted.\n");
				else if( status == failure )
					printf("Data not inserted.\n");

				break;


			case 4:	
				status = dl_delete_first(&head);
		
				if( status == success )
					printf("Data deleted.\n");
				else if( status == failure )
					printf("List does not exist.\n");

				break;


			case 5:	
				status = dl_delete_last(&head, &tail);
		
				if( status == success )
					printf("Data deleted.\n");
				else if( status == failure )
					printf("List does not exist.\n");

				break;

			case 6:
				status = dl_linklen(&head);
				break;

			case 7:
				read_element(&element), read_data(&data);
				status = dl_insert_after(&head, &tail, element, data);
		
				if( status == success )
					printf("Data inserted after %d element.\n", data);
				else if( status == failure )
					printf("Data not inserted.\n");

				break;

			case 8:
				read_element(&element), read_data(&data);
				status = dl_insert_before(&head, &tail, element, data);
		
				if( status == success )
					printf("Data inserted after %d element.\n", data);
				else if( status == mem_alloc_failure )
					printf("Memory allocation failed.\n");
				else if( status == data_not_found_failure )
					printf("Data not found.\n");
				break;

			case 9:
				read_element(&element);
				status = dl_delete_element(&head, &tail, element);

				if ( status == success )
					printf("Element deleted.\n");
				else if ( status == failure )
					printf("List does not exist.\n");
				else if ( status == data_not_found_failure )
					printf("Element not found.\n");
				break;

			case 10:
				status = dl_delete_list(&head, &tail);

				if ( status == success )
					printf("List deleted.\n");
				else if ( status == failure )
					printf("List does not exist.\n");
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
