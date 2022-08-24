#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);

	temp = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		temp->right = tree->left;
		tree->left->parent = temp;
	}
	else
		temp->right = NULL;
	temp->parent = tree;
	tree->left = temp;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
