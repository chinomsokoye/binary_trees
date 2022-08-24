#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is valid BST, otherwise 0 if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_help(tree, INT_MIN, INT_MAX));
}

/**
 * btib_help - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @low: Lower node checked
 * @high: Higher node checked
 * Return: 1 if tree is valid BST, otherwise 0 if tree is NULL
 */
int btib_help(const binary_tree_t *tree, int low, int high)
{
	if (!tree)
		return (1);
	if (tree->n < low || tree->n > high)
		return (0);
	return (btib_help(tree->left, low, tree->n - 1) && btib_help(
			tree->right, tree->n + 1, high));
}
