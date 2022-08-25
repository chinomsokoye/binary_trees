#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise, if tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btia_help(tree, INT_MIN, INT_MAX));
}

/**
 * btia_help - Check if binary tree is AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @low: Lower range
 * @high: Higher range
 * Return: 1 if tree is AVL Tree, 0 otherwise
 */
int btia_help(const binary_tree_t *tree, int low, int high)
{
	int side_l, side_r;

	if (!tree)
		return (1);
	if (tree->n < low || tree->n > high)
		return (0);
	side_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	side_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	if (abs(side_l - side_r) > 1)
		return (0);
	return (btia_help(tree->left, low, tree->n - 1) && btia_help(
			tree->right, tree->n + 1, high));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
