#ifndef TYPES_H
#define TYPES_H

typedef int data_t;



typedef struct _bst_t
{
	struct _bst_t *LC, *RC;
	data_t data;
}bst_t;



typedef enum
{
	no_list_failure, mem_failure, duplicate, success, found, not_found
}bool_bst;


//Insert node in tree
bool_bst bst_insert(bst_t **root, data_t data);

//Print nodes in In Order ( L->P->R )
bool_bst inorder_print(bst_t *root);

//Print nodes in Pre Order ( P->L->R )
bool_bst preorder_print(bst_t *root);

//Print nodes in Post Order ( L->R->P )
bool_bst postorder_print(bst_t *root);

//Find height of tree
int find_height(bst_t *root );

//Find number of nodes
int find_number_of_nodes(bst_t *root);

//Search a node
bool_bst bst_search_node(bst_t *root, data_t node);

//Find minimum node
bst_t * find_min_node(bst_t *root);

//Find maximum node
bst_t * find_max_node(bst_t *root);

//Search a node
bst_t * bst_delete_node(bst_t *root, data_t key);

#endif
