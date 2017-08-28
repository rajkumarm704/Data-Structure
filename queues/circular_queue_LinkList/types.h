#ifndef TYPES_H
#define TYPES_H

typedef int data_t;

typedef struct _Slist
{
	data_t data;
	struct _Slist *next;
}slist_t;

typedef enum
{
	queue_empty_failure, failure, success

}bool_queue_CLL;

/*	Function Prototypes	*/

//Create Node
slist_t * create_node(data_t value);

//Insert data at last node
bool_queue_CLL sl_insert_last(slist_t **head, data_t value);

//Delete data at first node
bool_queue_CLL sl_delete_first(slist_t **head);

//Display data of the list
bool_queue_CLL sl_display_list(slist_t **head);

#endif
