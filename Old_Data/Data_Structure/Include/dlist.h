#ifndef DLIST_H
#define DLIST_H

typedef int data_t;

typedef struct _dlist_t
{
	struct _dlist_t *prev;
	struct _dlist_t *next;
	data_t data;

}dlist_t;

typedef enum 
{
	failure, mem_alloc_failure, data_not_found_failure, success
}bool_e;

typedef bool_e bool_t;

//Display double link list
bool_t dl_display_list(dlist_t **head);

//Insert data at last of link list
bool_t dl_insert_last(dlist_t **head, dlist_t **tail, data_t data);

//Insert data at last of link list
bool_t dl_insert_first(dlist_t **head, dlist_t **tail, data_t data);

//Delete first element of list
bool_t dl_delete_first(dlist_t **head);

//Delete last element of list
bool_t dl_delete_last(dlist_t **head, dlist_t **tail);

//Find the link length
bool_t dl_linklen(dlist_t **head);

//Insert after an element
bool_t dl_insert_after(dlist_t **head, dlist_t **tail, data_t element, data_t data);

//Insert Before
bool_t dl_insert_before(dlist_t **head, dlist_t **tail, data_t element, data_t data);

//Delete element
bool_t dl_delete_element(dlist_t **head, dlist_t **tail, data_t element);

//Delete list
bool_t dl_delete_list(dlist_t **head, dlist_t **tail);

#endif


