#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashtable.h"

//Variable declared in main function file
extern int size;

//Create a File Table node
ftable_slist_t * create_ftable_node(char *fname)
{
	//Allocate memory for new node
	ftable_slist_t *new = malloc( sizeof(ftable_slist_t) );
	
	//Check if memory was allocated
	if (!new)
	{
		return NULL;
	}

	//Initialise the values
	new->fname = fname;
	new->wcount = 1;
	new->next = NULL;

	//Return new node
	return new;

}

//Create node function
word_slist_t * create_word_node(data_t word, char *fname)
{
	//Allocate memory for new node
	word_slist_t *new = malloc(sizeof(word_slist_t));

	//Create File Table node
	new->ftable_head = create_ftable_node(fname);

	//Copy the data into node
	new->word = strdup(word);

	//Initialise word & file count to 1
	new->fcount = 1;
	new->wcount = 1;
	
	//Make next link as NULL
	new->next = NULL;

	//Return new node
	return new;
}

//Update Word Node
bool_hash update_word_node( word_slist_t *ptr, data_t word, char *fname)
{
	ptr->wcount++;
	ptr->fcount++;

	ftable_slist_t *ftable_ptr = ptr->ftable_head;

	//Traverse through File table list
	while ( ftable_ptr )
	{
		//Check if the file name matches
		if ( strcmp(ftable_ptr->fname, fname) == 0 )
		{
			ftable_ptr->wcount++;
			return success;
		}

		//Move the pointer to next node
		if ( ftable_ptr->next != NULL )
		{
			ftable_ptr = ftable_ptr->next;
		}
		//Create new file table node if file name is different
		else
		{
			ftable_ptr->next = create_ftable_node(fname);
			return success;
		}

	}//while


}


//Insert a node at last of link list
void sl_insert_last(word_slist_t **head, word_slist_t **tail, data_t word, char *fname)
{
	//If list does not exist, create list and update head & tail
	if (*head == NULL)
	{
		*head = create_word_node(word, fname);
		*tail = *head;
		
	}

	//If list exists, append the new node to last
	else
	{
		//Initialise a ptr to head
		word_slist_t *word_ptr = *head;

		//Traverse through list until last node is reached
		while ( word_ptr )
		{
			//Check if the word matches; if true updaet informations
			if ( strcmp( word_ptr->word, word ) == 0 )
			{
				update_word_node( word_ptr, word, fname );	//Function Defination needed
				return;
			}//if

			//Move pointer to next node
			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				break;
			}

		}//while

		//Create new word node at last of list
		word_ptr->next = create_word_node(word, fname);

		//Update tail
		*tail = word_ptr->next;

	}//else

}

//Hash function
int hash_function(data_t word)
{
	int index;

	//Find the index of hash table using ASCII values
	if (*word >= 65 && *word <= 90)
	{
		index = *word - 65;
	}
	else if (*word >= 97 && *word <= 122)
	{
		index = *word - 97;
	}

	//Return calculated index 
	return index;
}

//Insert data into Hash Table
bool_hash hash_insert_data(HashStruct **hashtable, data_t word, char *fname)
{
	int index;

	//Find index of hash table by calling function
	index = hash_function(word);

	if (index > size)
	{
		return failure;
	}

	//Insert the nodes into table
	sl_insert_last(&(((*hashtable) + index)->head), &(((*hashtable) + index)->tail), word, fname);

	return success;

}

//Display Single Link List
bool_hash sl_display_list(word_slist_t *head)
{
	//If head does not exist, return failure
	if(head == NULL)
	{
		return failure;
	}

	//Else display list
	else
	{
		//Initialise temporary pointers for traversing through link lists
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		//Assign pointer
		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		//Traverse through word list and display data
		while( word_ptr )
		{
			//Display word node
			printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

			//Traverse through file table list and display data
			while( ftable_ptr )
			{
				//Display File table node
				printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);

				//Traverse through the file table list
				if ( ftable_ptr->next != NULL )
				{
					ftable_ptr = ftable_ptr->next;
				}
				else
				{
					break;
				}

			}//while	
			
			//Move the pointer to next node
			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				break;
			}
		

		}//while

		printf("\n\n");

	}//else

}

//Display Hash Table
bool_hash display_hashtable(HashStruct **hashtable)
{
	int index;
	
	//Return failure, if hash table is not present
	if (*hashtable == NULL)
	{
		return failure;

	}//if

	//Display hash table
	for (index = 0; index < size; index++)
	{
		//Call list display function
		sl_display_list( ( (*hashtable) + index )->head);

	}//for

	return success;
}


//Search Word Single Link List
bool_hash sl_search_list(word_slist_t *head, data_t word)
{
	//If head does not exist, return failure
	if(head == NULL)
	{
		return failure;
	}

	//Else display list
	else
	{
		//Initialise pointers
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		//Traverse through list and display data
		while( word_ptr )
		{
			//Check if word to be found is in the current node
			if ( strcmp(word_ptr->word, word) == 0 )
			{
				//Display word node
				printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

				//Display file table node
				while( ftable_ptr )
				{
					printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);

					//Move the pointer to next node
					if ( ftable_ptr->next != NULL )
					{
						ftable_ptr = ftable_ptr->next;
					}
					else
					{
						break;
					}

				}//while	
			}

			//Move the pointer to next node
			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				break;
			}
		

		}//while

		printf("\n\n");

	}//else

}

//Search Data
bool_hash search_data(HashStruct **hashtable, data_t word)
{
	int index;
	
	//Return failure, if hash table is not present
	if (*hashtable == NULL)
	{
		return failure;

	}//if

	//Display hash table
	for (index = 0; index < size; index++)
	{
		//Call list display function
		sl_search_list( ( (*hashtable) + index )->head, word);

	}//for
	return success;


}

//Backup Single Link List
bool_hash sl_backup_list(word_slist_t *head, int index, FILE *fp)
{
	//If head does not exist, return failure
	if(head == NULL)
	{
		return failure;
	}

	//Else display list
	else
	{
		//Initialise pointers
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		//Read the file index
		fprintf( fp, "%d #\n", index);

		//Traverse through word list and display data
		while( word_ptr )
		{
			//Display and save word node
//			printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);
			fprintf( fp, "%s ; %d ; %d ; ",  word_ptr->word, word_ptr->fcount, word_ptr->wcount );

			//Traverse through file table list and display data
			while( ftable_ptr )
			{
				//Display and save file table node
//				printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);
				fprintf(fp, "%s ; %d ; ", ftable_ptr->fname, ftable_ptr->wcount);

				//Move the pointer to next node
				if ( ftable_ptr->next != NULL )
				{
					ftable_ptr = ftable_ptr->next;
				}
				else
				{
					break;
				}

			}//while	

			//Adjust file fpi
			fseek(fp, -2l, SEEK_CUR);
			fprintf(fp,"#\n");

			//Move the pointer to next node
			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				//Adjust file fpi
				fseek(fp, -1l, SEEK_CUR);
				fprintf(fp,"#\n");
				break;
			}


		}//while

//		printf("\n\n");

	}//else
}


//Backup Hash Table Data
bool_hash backup_hashtable(HashStruct **hashtable)
{

	int index;

	FILE *fp = NULL;

	//Create a file to store data
	fp = fopen("Database.txt", "w");

	//Check if file was opened successfully
	if (!fp)
	{
		return failure;
	}

	//Return failure, if hash table is not present
	if (*hashtable == NULL)
	{
		return failure;

	}//if

	//Display hash table
	for (index = 0; index < size; index++)
	{
		//Call list display function
		sl_backup_list( ( (*hashtable) + index )->head, index, fp);

	}//for

	//Close file after saving data
	fclose(fp);

	return success;

}

//Update File Table Node
bool_hash update_ftable_node( ftable_slist_t *ftable_ptr, char *fname)
{
	//Create a word node if there was none
	if ( ftable_ptr == NULL )
	{
		ftable_ptr = create_ftable_node(fname);
		return success;
	}

	//Create a node at last of list
	else
	{
		ftable_slist_t *ftable_ptr_temp = ftable_ptr;		

		//Traverse through file table pointer
		while ( ftable_ptr_temp )
		{
			//Update information if data is same in the node
			if ( strcmp(ftable_ptr_temp->fname, fname) == 0 )
			{
				ftable_ptr_temp->wcount++;
				return success;
			}

			//Move the pointer to next node
			if ( ftable_ptr_temp->next != NULL )
			{
				ftable_ptr_temp = ftable_ptr_temp->next;
			}
			else
			{
				ftable_ptr_temp->next = create_ftable_node(fname);
				return success;
			}//else

		}//while

	}//else

}


//Update data into Single Link List
bool_hash sl_update_list(word_slist_t **head, int index, FILE *fp)
{
	int findex;
	char fword[20];

	word_slist_t *word_ptr = NULL;
	ftable_slist_t *ftable_ptr = NULL;


	fscanf( fp, "%d #", &findex);

	//If index matches, update list
	if ( index == findex )
	{
//		printf("\nIndex matched!!!\n");

		*head = create_word_node("", "");

		word_ptr = *head;
		ftable_ptr = (*head)->ftable_head;
		
		//Read word node
word_node:	fscanf( fp, "%s ; %d ; %d ; ",  fword, &word_ptr->fcount, &word_ptr->wcount );
		word_ptr->word = strdup(fword);
//		printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

		//Read file table node
ftable_node:	fscanf(fp, "%s ; %d ; ", fword, &ftable_ptr->wcount);
		ftable_ptr->fname = strdup(fword);
//		printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);

		//If the first word node is ended, create a new node if data is present
		if ( fgetc(fp) == '#' )
		{
			//Return if all data of an index is read from file
			if ( fgetc(fp) == '#' )
			{	
//				printf("\n");
//				printf("\nFinal updated New list\t");
//				sl_display_list(*head), printf("\n");
				return success;
			}

			//Create a word node at last if data is present
			word_ptr->next = create_word_node("", "");
			word_ptr = word_ptr->next;

			//GOTO Read word node
			goto word_node;
		}

		//Read data if frame is not ended
		else
		{
			//Adjust file fpi
			fseek(fp, -1l, SEEK_CUR);

			//Create a node at last of file table node
			ftable_ptr->next = create_ftable_node("");
			ftable_ptr = ftable_ptr->next;

			//GOTO Read file table node
			goto ftable_node;

		}//else

	}//if

	//Return failure, if index not found
	else
	{
		//Adjust file fpi
		fseek(fp, -4l, SEEK_CUR);

		//Return failure, if index not found
		return failure;
	
	}//else
}


//Update Data into Hash Table
bool_hash update_hashtable(HashStruct **hashtable)
{

	int index;
	long int fpi;
	FILE *fp = NULL;

	//Open the database file in read mode
	fp = fopen("Database.txt", "r");

	//Check if file contains any data
	fseek(fp, 0l, SEEK_END);
	fpi = ftell(fp);
	fseek(fp, 0l, SEEK_SET);
	
	//Return if no data exist in database file
	if (!fpi)
	{
		return database_empty_failure;
	}

	//Check if file was opened successfully
	if (!fp)
	{
		return failure;
	}

	//Return failure, if hash table is not present
	if (*hashtable == NULL)
	{
		return failure;

	}//if

	//Display hash table
	for (index = 0; index < size; index++)
	{
		//Call list display function
		sl_update_list( &( ( (*hashtable) + index )->head), index, fp);

	}//for

	//Close the file after reading data
	fclose(fp);

	return success;

}
