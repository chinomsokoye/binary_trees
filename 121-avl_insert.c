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

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int bal = 0;
	avl_t *node = bst_insert(tree, value);

	bal = binary_tree_balance(*tree);

	if (bal > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	else if (bal < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	else if (bal > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	else if (bal < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}
