#ifndef SLIST_H
#define SLIST_H

typedef int data_t;

typedef struct _Slist
{
	data_t data;
	struct _Slist *next;
}slist_t;


/*	Function Prototypes	*/

//Create Node
slist_t * create_node(data_t value);

//Insert data at first node
void sl_insert_first(slist_t **head, data_t value);

//Insert data at last node
void sl_insert_last(slist_t **head, data_t value);

//Delete data at first node
void sl_delete_first(slist_t **head);

//Delete data at last node
void sl_delete_last(slist_t **head);

//Display data of the list
void sl_display_list(slist_t **head);

//Find the link list length
int sl_linklen(slist_t **head);

//Delete entire link list
void sl_delete_list(slist_t **head);

//Insert an element after the specified value
void sl_insert_after(slist_t **head, data_t value, data_t element);

//Insert an element before the specified value
void sl_insert_before(slist_t **head, data_t value, data_t element);

//Find a node from the list
slist_t *sl_find_node(slist_t **head, data_t element);

//Delete a specified element
int sl_delete_element(slist_t **head, data_t element);

//Insert an element at nth position in the link list
void sl_insert_nth(slist_t **head, data_t value, int n);

//Find the mid-point of link list
slist_t *sl_find_mid_element(slist_t **head);

//Find the nth element from last
slist_t *sl_get_nth_from_last(slist_t **head, int n);

//Sort the given link list
void sl_sort_list(slist_t **head);

//Reverse link list
void sl_reverse_iterative(slist_t **head);

//Remove repeated elements from list
void sl_remove_repeated(slist_t **head);

//Create a looped link list
int sl_create_loop(slist_t **head);

//Find loop in link list
int sl_find_loop(slist_t **head);

//Sort Merge
void sl_sort_merge(slist_t **head1, slist_t **head2);

//Reverse recurrsion
void sl_reverse_recursive(slist_t **head, slist_t **head_next);

#endif






