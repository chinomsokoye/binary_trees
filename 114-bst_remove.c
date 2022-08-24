#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree where you will remove node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_min_val(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_min_val - Finds the smallest node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_min_val(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;
	return (min);
}
