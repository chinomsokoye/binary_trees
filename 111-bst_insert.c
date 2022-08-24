#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *second = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	temp = *tree;
	while (temp)
	{
		second = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}
	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}
	return (new);
}
