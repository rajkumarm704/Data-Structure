#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"file_processing.h"
#include"hashtable.h"

//Process inputs from user
bool_hash file_processing(HashStruct **hashtable, int argc, char **argv)
{
	int i, j = 0;
	char ch, word[20];
	
	FILE *fp = NULL;

	//Read all files
	for (i = 1; i < argc; i++)
	{
		//Open the ith file in read mode
		fp = fopen(argv[i], "r");

		//Read first character
		ch = fgetc(fp);

		//Read all words untill end of file
		while ( ch != EOF )
		{
			//Read all characters and form word
			if ( ch != ' ' && ch != '\n' && ch != '\t' && ch != '.' && ch != ',' )
			{
				//Put data into buffer to form word
				word[j] = ch;
				j++;
		
				//Read the character
				ch = fgetc(fp);
			}
	
			//Insert null character at end and store data into Hash Table
			else
			{
				word[j] = '\0';
				j = 0;

//				printf("%s\tlength:%d\n", word, (int)strlen(word) );

				//Read the character
				ch = fgetc(fp);


				if ( !strlen(word))
				{
					continue;
				}

				//Call insert data function
				hash_insert_data(hashtable, word, argv[i]);
			}

		}//while

		//Close file after reading all characters
		fclose(fp);
		fp = NULL;

	}//for

	return success;

}
