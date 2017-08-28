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

	bst_t *root = NULL, *node = NULL;
	data_t data;
	int option, count, result;
	bool_bst status;

	while(1)
	{
		printf("\n\nChoose an operation from below:\n"
			"1.	 Insert Element\n"
			"2.	 In order print\n"
			"3.	 Pre order print\n"
			"4.	 Post order print\n"
			"5.	 Find height\n"
			"6.	 Find number of nodes\n"
			"7.	 Search node\n"
			"8.	 Find minimum node\n"
			"9.	 Find maximum node\n"
			"10.	 Delete node\n"
			"100.	 Exit\n"
			"Enter your choice: ");
		scanf("%d", &option);
				printf("\n\n");
		switch(option)
		{
			case 1:	
				read_data(&data);
				status = bst_insert(&root, data);
	
				if ( status == success )
					printf("Node inserted successfully.\n");
				else if ( status == duplicate )
					printf("Duplicate data not allowed.\n");
				else if ( status == mem_failure )
					printf("Memory was full.\n");
				break;


			case 2:
				inorder_print(root);
				break;

			case 3:
				preorder_print(root);
				break;

			case 4:
				postorder_print(root);
				break;


			case 5:
				count = find_height(root);

				if ( count == 0 )
					printf("No list present\n");

				else
					printf("The height is:%d\n", count);
				break;

			case 6: 
				count = find_number_of_nodes(root);

				if ( count == 0 )
					printf("No list present\n");

				else
					printf("The number of nodes are:%d\n", count);
				break;

			case 7:	
				read_data(&data);
				status = bst_search_node(root, data);

				if ( status == found )
					printf("Data found.\n");
				else if ( status == not_found )
					printf("Data not found.\n");

				break;

			case 8:
				node = find_min_node(root);

				if ( node )
					printf("The minimum data is %d.\n", node->data);
				else
					printf("Minimum data not found.\n");

				break;
				

			case 9:
				node = find_max_node(root);

				if ( node )
					printf("The maximum data is %d.\n", node->data);
				else
					printf("maximum data not found.\n");

				break;

			case 10:
				read_data(&data);
				bst_delete_node(root, data);

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
