#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#include"hashtable.h"
#include"file_processing.h"

//Global variable for size of hash table
int size = 26;

//Read data from user function
void read_word(data_t word)
{
	__fpurge(stdin);
	printf("Enter key:"), scanf("%[^\n]", word);
	__fpurge(stdin);
}


int main(int argc, char *argv[])
{

	system("clear");

	int option;
	HashStruct *hashtable = NULL;
	data_t word;
	bool_hash status;

	while(1)
	{
		//Show the menu to user
		printf("\n\nChoose an operation from below:\n"
			"1.	 Create Hash Table\n"
			"2.	 Insert data into Hash Table\n"
			"3.	 Search data in Hash Table\n"
			"4.	 Display DB\n"
			"5.	 Backup DB\n"
			"6.	 Update DB\n"
			"100.	 Exit\n"
			"Enter your choice: ");

		//Prompt user for option
		scanf("%d", &option), printf("\n\n");

		//Perform operation selected by user
		switch(option)
		{
			//Create Database(hash table)
			case 1:	

				//Check if Hash Table exists
				if ( hashtable != NULL )
				{
					printf("Hash Table has been already created and data has been inserted. Try displaying data...\n");
				}//if
	
				//Create Hash Table
				else
				{
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

				}//else

				break;

			//Insert data into Hash Table
			case 2:

				//Call function to process file data
				status = file_processing(&hashtable, argc, argv);

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

				//Read word to search in Database
				read_word(word);

				//Call Search data function
				status = search_data(&hashtable, word);
				break;

			//Display data in Hash Table
			case 4:

				//Call delete data function
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

			//Backup Hash Table
			case 5:

				//Call Backup function
				status = backup_hashtable(&hashtable);

				//Display status of function
				if (status == success)
				{
					printf("Data backup completed\n");
				}
				else if (status == failure)
				{
					printf("There was a problem in data Back Up. Please try again...\n");
				}
				break;

			//Update Hash Table
			case 6:

				//Call Update function
				status = update_hashtable(&hashtable);

				//Display status of function
				if (status == success)
				{
					printf("\nData Updation completed\n");
				}
				else if (status == failure)
				{
					printf("\nThere was a problem in data Updation. Please try again...\n");
				}
				else if (status == database_empty_failure)
				{
					printf("There is no data in Database!!! Please try again...\n");
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
