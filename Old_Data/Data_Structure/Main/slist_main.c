#include<stdio.h>
#include<stdlib.h>
#include<slist.h>

void read_data(data_t *data)
{
	printf("Enter data:"), scanf("%d", data);
}

void read_element(data_t *element)
{
	printf("Enter element:"), scanf("%d", element);
}

void read_n(int *n)
{
	printf("Enter n:"), scanf("%d", n);
}

int main()
{

	system("clear");

	int option, n;
	data_t data, element;
	slist_t *head = NULL;
	slist_t *mid_element = NULL;

	bool_slist status;

	while(1)
	{
		printf("\n\nChoose an operation from below:\n"
			"1.	 insert_first\n"
			"2.	 insert_last\n"
			"3.	 delete_first\n"
			"4.	 delete_last\n"
			"5.	 Display list\n"
			"6.	 Find Link length\n"
			"7.	 Insert after\n"
			"8.	 Insert before\n"
			"9.	 Delete List\n"
			"10.	 Find Node\n"
			"11.	 Delete Node\n"
			"12.	 Insert nth\n"
			"13.	 Find Mid Element\n"
			"14.	 Find nth Element from last\n"
			"15.	 Sort list\n"
			"16.	 Reverse link list (Iterative)\n"
			"17.	 Remove repeated element\n"
			"18.	 Insert Sort element\n"
			"19.	 Mid point element(single iteration)\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n\n");
		switch(option)
		{
			case 1:	
				read_data(&data);
				sl_insert_first(&head, data);
				break;

			case 2:	
				read_data(&data);
				sl_insert_last(&head, data);
				break;
			case 3:	
				sl_delete_first(&head);
				break;
			case 4:	
				sl_delete_last(&head);
				break;
			case 5:	
				sl_display_list(&head);
				break;
			case 6:	
				printf("Link Length is %d\n", sl_linklen(&head) );
				break;

			case 7:	
				read_data(&data);
				read_element(&element);
				sl_insert_after(&head, data, element);
				break;

			case 8:	
				read_data(&data);
				read_element(&element);
				sl_insert_before(&head, data, element);
				break;

			case 9:	
				sl_delete_list(&head);
				break;

			case 10:
				read_element(&element);
				if( sl_find_node(&head, element) != NULL )
					printf("Element found\n");
				else
					printf("Element not found\n");
				break;

			case 11:
				read_element(&element);
				if( sl_delete_element(&head, element) == 1 )
					printf("Element deleted successfully.\n");
				else
					printf("Element was not deleted\n");
				break;

			case 12:
				read_data(&data);
				read_n(&n);
				sl_insert_nth(&head, data, n);
				break;

			case 13:
				sl_find_mid_element(&head);
				break;

			case 14:
				read_n(&n);
				sl_get_nth_from_last(&head, n);
				break;

			case 15:
				sl_sort_list(&head);
				break;

			case 16:
				sl_reverse_iterative(&head);
				break;

			case 17:
				sl_remove_repeated(&head);
				break;

			case 18:
				read_data(&data);
				status = insert_sort(&head, data);

				if ( status == success )
					printf("Data has been inserted.\n");
				else if ( status == failure )
					printf("No list present\n");
				break;

			case 19:
				element = sl_find_midpoint_single_iter(&head);

				printf("The midpoint is %d\n", element);
				break;


			case 100:	
				printf("The program will exit now...\n");
				return 0;


			default:
				printf("Wrong option selected...Please try again...\n");
		}

	}

}
