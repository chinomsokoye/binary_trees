#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL Tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the node of the created AVL Tree, NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i = 0;
	avl_t *root = NULL;

	while (i < size)
	{
		avl_insert(&root, array[i]);
		i++;
	}
	return (root);
}
