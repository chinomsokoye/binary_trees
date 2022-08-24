#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: Integer value to store in new node
 * Return: Pointer to created node, NULL on failure if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;
	if (new->left)
		new->left->parent = new;
	return (new);
}
