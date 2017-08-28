#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashtable.h"

//Variable declared in main function file
extern int size;

//Create a File Table node
ftable_slist_t * create_ftable_node(char *fname)
{
	ftable_slist_t *new = malloc( sizeof(ftable_slist_t) );
	
	if (!new)
	{
		return NULL;
	}

	new->fname = fname;
	new->wcount = 1;
	new->next = NULL;

	return new;

}


//Create node function
word_slist_t * create_word_node(data_t word, char *fname)
{
	//Allocate memory for new node
	word_slist_t *new = malloc(sizeof(word_slist_t));

	//Create file table head
	new->ftable_head = NULL;

	//Copy the data into node
	new->word = strdup(word);

	//If file table does not exist, create it and initialise word & file count to 1
	if ( new->ftable_head == NULL )
	{
		//Create File Table
		new->ftable_head = create_ftable_node(fname);

		//Initialise word & file count to 1
		new->fcount = 1;
		new->wcount = 1;
	}
	
	//Make next link as NULL
	new->next = NULL;

	//Return new node
	return new;
}

//Update File Table Node
bool_hash update_ftable_node( ftable_slist_t *ftable_ptr, char *fname)
{


}


//Update Word Node
bool_hash update_word_node( word_slist_t *ptr, data_t word, char *fname)
{
	ptr->wcount++;
	ptr->fcount++;

	ftable_slist_t *ftable_ptr = ptr->ftable_head;

	while ( ftable_ptr )
	{
		if ( strcmp(ftable_ptr->fname, fname) == 0 )
		{
			update_ftable_node(ftable_ptr, fname);		//Function Defination needed
			ftable_ptr->wcount++;
			return success;
		}

		if ( ftable_ptr->next != NULL )
		{
			ftable_ptr = ftable_ptr->next;
		}
		else
		{
			ftable_ptr->next = create_ftable_node(fname);	//Function Defination needed
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
			if ( strcmp( word_ptr->word, word ) == 0 )
			{
				update_word_node( word_ptr, word, fname );	//Function Defination needed
				return;
			}//if

			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				break;
			}

		}//while

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
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		//Traverse through list and display data
		while( word_ptr )
		{
//			printf("WORD NODE\nword:%s, fcount:%d, wcount:%d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);
			printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

			while( ftable_ptr )
			{
//				printf("FILE TALE NODE\nfname:%s, fcount:%d->\n\n", ftable_ptr->fname, ftable_ptr->wcount);
				printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);
				if ( ftable_ptr->next != NULL )
				{
					ftable_ptr = ftable_ptr->next;
				}
				else
				{
					break;
				}

			}//while	
			
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
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		//Traverse through list and display data
		while( word_ptr )
		{

			if ( strcmp(word_ptr->word, word) == 0 )
			{

				printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

				while( ftable_ptr )
				{
					printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);
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
		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = NULL;

		if ( word_ptr->ftable_head != NULL)
		{
			ftable_ptr = word_ptr->ftable_head;
		}

		fprintf( fp, "%d #\n", index);

		//Traverse through list and display data
		while( word_ptr )
		{
			printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

			fprintf( fp, "%s ; %d ; %d ; ",  word_ptr->word, word_ptr->fcount, word_ptr->wcount );

			while( ftable_ptr )
			{
//				printf("FILE TALE NODE\nfname:%s, fcount:%d->\n\n", ftable_ptr->fname, ftable_ptr->wcount);
				printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);

				fprintf(fp, "%s ; %d ; ", ftable_ptr->fname, ftable_ptr->wcount);

				if ( ftable_ptr->next != NULL )
				{
					ftable_ptr = ftable_ptr->next;
				}
				else
				{
					break;
				}

			}//while	

			fseek(fp, -2l, SEEK_CUR);
			fprintf(fp,"#\n");

			if ( word_ptr->next != NULL )
			{
				word_ptr = word_ptr->next;
			}
			else
			{
				fseek(fp, -1l, SEEK_CUR);
				fprintf(fp,"#\n");
				break;
			}


		}//while

		printf("\n\n");

	}//else
}


//Backup Hash Table Data
bool_hash backup_hashtable(HashStruct **hashtable)
{

	int index;

	FILE *fp = NULL;

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

	fclose(fp);

	return success;

}


//Update data into Single Link List
bool_hash sl_update_list(word_slist_t *head, int index, FILE *fp)
{
	int findex;
	char fword[20];

//	printf("\tbefore fpi:%ld\t", ftell(fp) );
	fscanf( fp, "%d #", &findex);
//	printf("findex:%d\t", findex);
//	printf("after fpi:%ld\t", ftell(fp) );

	//If index matches, update list
	if ( index == findex )
	{
		printf("\nIndex matched!!!\n");

		head = create_word_node("", "");
		head->ftable_head = create_ftable_node("");

		word_slist_t *word_ptr = head;
		ftable_slist_t *ftable_ptr = head->ftable_head;

word_node:	fscanf( fp, "%s ; %d ; %d ; ",  fword, &word_ptr->fcount, &word_ptr->wcount );
		word_ptr->word = strdup(fword);
		printf("\n%s, %d, %d\n", word_ptr->word, word_ptr->fcount, word_ptr->wcount);

start:		fscanf(fp, "%s ; %d ; ", fword, &ftable_ptr->wcount);
		ftable_ptr->fname = strdup(fword);
		printf("%s, %d------->", ftable_ptr->fname, ftable_ptr->wcount);

		if ( fgetc(fp) == '#' )
		{
			if ( fgetc(fp) == '#' )
			{
				printf("\n");	
				return success;
			}

			//Insert the nodes into table
			sl_insert_last( &head, &head, word_ptr->word, ftable_ptr->fname);


			goto word_node;
		}
		else
		{
			fseek(fp, -1l, SEEK_CUR);
			goto start;

		}//else

	}//if
	else
	{
//		printf("\tafter fpi:%ld\n", ftell(fp) );
		fseek(fp, -4l, SEEK_CUR);
		return failure;
	
	}//else
}


//Update Data into Hash Table
bool_hash update_hashtable(HashStruct **hashtable)
{

	int index;

	FILE *fp = NULL;

	fp = fopen("Database.txt", "r");

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
//		printf("iter:%d\t", index);

		//Call list display function
		sl_update_list( ( (*hashtable) + index )->head, index, fp);

	}//for

	fclose(fp);

	return success;

}
