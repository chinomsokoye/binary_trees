#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 *
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 * Return: Pointer to the node containing a value equals to @value
 * Null if tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);
	while (node)
	{
		if (value == node->n)
			return (node);
		else if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}
	return (NULL);
}
