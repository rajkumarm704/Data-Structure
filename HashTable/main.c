#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#include"hash.h"

//Global variable for size of hash table
int size;

//Read size of hash table function
void read_size(int *size)
{
	printf("Enter size of array:"), scanf("%d", size);
}

//Read data from user function
void read_data(data_t key)
{
	__fpurge(stdin);
	printf("Enter key:"), scanf("%[^\n]", key);
	__fpurge(stdin);
}


int main()
{

	system("clear");

	int option;
	HashStruct *hashtable;
	data_t key;
	slist_t *head = NULL, *tail = NULL, *result = NULL;
	bool_hash status;

	while(1)
	{
		//Show the menu to user
		printf("\n\nChoose an operation from below:\n"
			"1.	 Create Hash Table\n"
			"2.	 Insert data in Hash Table\n"
			"3.	 Search data in Hash Table\n"
			"4.	 Delete data in Hash Table\n"
			"5.	 Delete Hash Table\n"
			"6.	 Display Hash Table\n"
			"100.	 Exit\n"
			"Enter your choice: ");

		//Prompt user for option
		scanf("%d", &option), printf("\n\n");

		//Perform operation selected by user
		switch(option)
		{
			//Create hash table
			case 1:	
				//Read size from user
				read_size(&size);

				//Allocate memory for hash table
				hashtable = malloc(size * sizeof(HashStruct));

				//Check if memory was allocated
				if (hashtable == NULL)
				{
					printf("Memory is full. Please try again later...\n");
				}
				else if (hashtable != NULL)
				{
					printf("Hash table created...\n");
				}
				break;

			//Insert data into hash table
			case 2:
				//Read key from user
				read_data(key);

				//Call function to insert data
				status = hash_insert_data(&hashtable, key);

				//Display status of function
				if (status == success)
				{
					printf("Data successfully inserted.\n");
				}
				else if (status == failure)
				{
					printf("Wrong data. Please try again.\n");
				}

				break;

			//Search data in Hash Table
			case 3:
				//Read key from user
				read_data(key);

				//Call search function
				result = hash_search_data(&hashtable, key);

				//Display message according to the return status
				if (result != NULL)
				{
					printf("Data is found. The data is %s. The address of node is %p\n", result->data, result);
				}
				else
				{
					printf("Data not found.\n");
				}
	
				break;

			//Delete data in Hash Table
			case 4:
				//Read key from user
				read_data(key);

				//Call delete data function
				status = delete_data_in_hashtable(&hashtable, key);

				//Display status of function
				if (status == success)
				{
					printf("Data successfully deleted.\n");
				}
				else if (status == failure)
				{
					printf("Data not deleted. Please try again.\n");
				}

				break;

			//Delete Hash Table
			case 5:
				//Call delete table function
				status = delete_hashtable(&hashtable);

				//Display status of function
				if (status == success)
				{
					printf("Hash table successfully deleted.\n");
				}
				else if (status == failure)
				{
					printf("Table was not deleted. Please try again.\n");
				}


				//Free hash table
				free(hashtable);

				//Reset the pointers
				hashtable = NULL;
				head = NULL, tail = NULL, result = NULL;

				break;

			//Display Hash Table
			case 6:
				//Call display hash table function
				status = display_hashtable(&hashtable);

				//Display status of function
				if (status == success)
				{
					printf("Hash table displayed successfully.\n");
				}
				else if (status == failure)
				{
					printf("Table does not exist.\n");
				}


				break;

			//Quit the application
			case 100:	
				printf("The program will exit now...\n");
				return 0;


			default:
				printf("Wrong option selected...Please try again...\n");
		}//switch

	}//while




	return 0;
}
