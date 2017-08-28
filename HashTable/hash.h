#ifndef HASH_H
#define HASH_H

//User defined data type for data to store into link list
typedef char * data_t;

//User defined data type for flag 
typedef enum
{
	failure, success
}bool_hash;

//Single link list structure
typedef struct _Slist
{
	data_t data;
	struct _Slist *next;
}slist_t;

//Hash Table structure
typedef struct _hash_struct
{
	slist_t *head;
	slist_t *tail;

}HashStruct;


/*	Function Prototypes	*/

//Hash function
int hash_function(data_t key);

//Insert data into Hash Table
bool_hash hash_insert_data(HashStruct **hashtable, data_t key);

//Display Hast Table
bool_hash display_hashtable(HashStruct **hashtable);

//Search Data
slist_t* hash_search_data(HashStruct **hashtable, data_t key);

//Delete data in hashtable
bool_hash delete_data_in_hashtable(HashStruct **hashtable, data_t key);

//Delete the hash table
bool_hash delete_hashtable(HashStruct **hashtable);

//Delete the hash table
bool_hash delete_hashtable(HashStruct **hashtable);


#endif
