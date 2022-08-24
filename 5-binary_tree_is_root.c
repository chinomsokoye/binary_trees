#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 *
 * @node: Pointer to the node to check
 * Return: 1 if node is root, 0 if node is NULL and ohterwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
