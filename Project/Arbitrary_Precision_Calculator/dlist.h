#ifndef DLIST_H
#define DLIST_H

//#include "types.h"

typedef int data_t;

typedef struct _dlist_t
{
	struct _dlist_t *prev;
	struct _dlist_t *next;
	data_t data;

}dlist_t;

typedef enum 
{
	failure_dl, success_dl
}bool_t;

//Display double link list
bool_t dl_display_list(dlist_t **head, APC_struct *apc_struct);

//Insert data at last of link list
bool_t dl_insert_last(dlist_t **head, dlist_t **tail, data_t data);

//Insert data at last of link list
bool_t dl_insert_first(dlist_t **head, dlist_t **tail, data_t data);

#endif



