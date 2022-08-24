#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i = 0;
	bst_t *root = NULL;

	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
