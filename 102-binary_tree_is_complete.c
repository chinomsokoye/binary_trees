#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (btic_help(tree, 0, size));
}

/**
 * btic_help - Checks if binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * @idx: Index
 * @size: Size
 * Return: if complete 1, otherwise NULL, 0
 */
int btic_help(const binary_tree_t *tree, size_t idx, size_t size)
{
	if (!tree)
		return (1);
	if (idx >= size)
		return (0);
	return (btic_help(tree->left, 2 * idx + 1, size) && btic_help(
			tree->right, 2 * idx + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node to measure the size
 * Return: 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
