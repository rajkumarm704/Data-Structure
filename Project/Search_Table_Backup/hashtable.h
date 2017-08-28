#ifndef HASH_H
#define HASH_H

//User defined data type for data to store into link list
typedef char * data_t;

//User defined data type for flag 
typedef enum
{
	failure, success
}bool_hash;

//Single link list structure for file table
typedef struct _ftable_slist_t
{
	data_t fname;
	int wcount;
	struct _ftable_slist_t *next;

}ftable_slist_t;

//Single link list structure for main data
typedef struct _word_slist_t
{
	data_t word;
	int fcount, wcount;
	ftable_slist_t *ftable_head;
	struct _word_slist_t *next;

}word_slist_t;


//Hash Table structure
typedef struct _hash_struct
{
	word_slist_t *head;
	word_slist_t *tail;

}HashStruct;


/*	Function Prototypes	*/

//Hash function
int hash_function(data_t word);

//Insert data into Hash Table
bool_hash hash_insert_data(HashStruct **hashtable, data_t word, char *fname);

//Display Hast Table
bool_hash display_hashtable(HashStruct **hashtable);

//Search Data
bool_hash search_data(HashStruct **hashtable, data_t word);

//Search Word Single Link List
bool_hash sl_search_list(word_slist_t *head, data_t word);

//Backup Hash Table Data
bool_hash backup_hashtable(HashStruct **hashtable);

//Update Data into Hash Table
bool_hash update_hashtable(HashStruct **hashtable);

//Update Data into Hash Table
bool_hash update_hashtable(HashStruct **hashtable);

#endif
