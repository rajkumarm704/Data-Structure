#include<stdio.h>
#include<stdlib.h>


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
		fp = fopen(argv[i], "r");
		
		ch = fgetc(fp);

		//Read all words
		while ( ch != EOF )
		{
			if ( ch != ' ' && ch != '\n' && ch != '\t' && ch != '.' && ch != ',' )
			{
				word[j] = ch;
				j++;
				ch = fgetc(fp);
			}
			else
			{
				word[j] = '\0';
				j = 0;
				ch = fgetc(fp);
				hash_insert_data(hashtable, word, argv[i]);
			}

		}//while

		fclose(fp);
		fp = NULL;

	}//for

	return success;

}
