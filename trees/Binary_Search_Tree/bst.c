#include<stdio.h>
#include<stdlib.h>

#include"types.h"

//Insert a node in tree
bool_bst bst_insert(bst_t **root, data_t data)
{

	//Allocate memory for new node
	bst_t *new = malloc(sizeof(bst_t));
	
	//Check if memory was allocated
	if (!new)
		return mem_failure;

	//Copy the data to new node
	new->data = data;

	//Make LC & RC node as NULL
	new->LC = new->RC = NULL;

	//If there is no root node, assign new node as root and return
	if (*root == NULL)
	{
		*root = new;
		return success;
	}

	//Initialise a temporary & parent pointer
	bst_t *temp = *root, *parent;

	//Run the loop till Nodes in tree exist
	while (temp)
	{
		//Make current node as parent node
		parent = temp;

		//If data to insert is smaller than current node data, move the pointer further to LC node
		if (data < temp->data)
		{
			temp = temp->LC;
		}

		//If data to insert is greater than current node data, move the pointer further to RC node
		else if (data > temp->data)
		{
			temp = temp->RC;
		}

		//If data to insert is equal to current node data, return duplicate error
		else
		{
			return duplicate;
		}

	}//while

	//If data to insert is smaller than parent data, make new node as LC node
	if (data < parent->data)
	{
		parent->LC = new;
	}

	//If data to insert is greater than parent data, make new node as RC node
	else
	{
		parent->RC = new;
	}

	return success;

}

//Print nodes in In Order (L->P->R)
bool_bst inorder_print(bst_t *root)
{
	//If root node exists, recursively call function to print all data
	if (root)
	{
		inorder_print(root->LC);
		printf("%d ", root->data);	
		inorder_print(root->RC);

	}//if

}

//Print nodes in Pre Order (P->L->R)
bool_bst preorder_print(bst_t *root)
{
	//If root node exists, recursively call function to print all data
	if (root)
	{
		printf("%d ", root->data);	
		preorder_print(root->LC);
		preorder_print(root->RC);

	}//if

}

//Print nodes in Post Order (L->R->P)
bool_bst postorder_print(bst_t *root)
{
	//If root node exists, recursively call function to print all data
	if (root)
	{
		postorder_print(root->LC);
		postorder_print(root->RC);
		printf("%d ", root->data);

	}//if

}

//Find height of tree
int find_height(bst_t *root)
{
	//If root node exists, recursively call function to find height
	if (root)
	{
		//Store LC level count
		int LC = find_height(root->LC);

		//Store RC level count
		int RC = find_height(root->RC);

		//If LC count is greater than RC count, increment count by 1 and return 
		if (LC > RC)
		{
			return LC + 1;
		}

		//If LC count is smaller than RC count, increment count by 1 and return 
		else
		{
			return RC + 1;
		}

	}//if
}


//Find number of nodes ***Not working
int find_number_of_nodes(bst_t *root)
{
	//If root node exists, recursively call function to find height
	if (root)
	{
		//Store LC level count
		int LC = find_height(root->LC);

		//Store RC level count
		int RC = find_height(root->RC);

		//Return sum of present nodes plus one
		return LC + RC + 1;

	}//if

}

//Search a node
bool_bst bst_search_node(bst_t *root, data_t node)
{
	bool_bst status;

	//If root node exists, recursively call function to find height
	if (root)
	{
		//Store the data found/not found status of LC node
		status = bst_search_node(root->LC, node);

		//If data to search is equal to current data, return found
		if (node == root->data || status == found)
		{
			return found;
		}

		//Store the data found/not found status of RC node
		status = bst_search_node(root->RC, node);

		//If data to search is equal to current data, return found
		if (node == root->data || status == found)
		{
			return found;
		}

		return not_found;

	}//if

}

//Find minimum node
bst_t * find_min_node(bst_t *root)
{
	bst_t * current = root;

	//Goto leftmost node
	while (current->LC != NULL)
	{
		current = current->LC;
	}

	return current;

}

//Find maximum node
bst_t * find_max_node(bst_t *root)
{
	bst_t * current = root;

	//Goto rightmost node
	while (current->RC != NULL)
	{
		current = current->RC;
	}

	return current;

}

//Delete node
bst_t * bst_delete_node(bst_t *root, data_t key)
{
	// base case
	if (root == NULL)
	{
		return root;
	}

	// If the key to be deleted is smaller than the root's key, goto left sub tree
	if (key < root->data)
	{
		root->LC = bst_delete_node(root->LC, key);
	}

	// If the key to be deleted is greater than the root's key, goto right sub tree
	else if (key > root->data)
	{
		root->RC = bst_delete_node(root->RC, key);
	}

	// if key is same as root's key, then current node is to be deleted
	else
	{
		// node with only one child or no child
		if (root->LC == NULL)
		{
			bst_t *temp = root->RC;
			free(root);
			return temp;
		}
		else if (root->RC == NULL)
		{
			bst_t *temp = root->LC;
			free(root);
			return temp;
		}

		// node with two children: get smallest in the RC subtree
		bst_t * temp = find_min_node(root->RC);

		// Copy the smallest node content to this node
		root->data = temp->data;

		// Delete smallest data node
		root->RC = bst_delete_node(root->RC, temp->data);
	}
	return root;
}
