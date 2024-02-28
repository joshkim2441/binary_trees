#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array
 * to be converted
 * @size: the number of elements in the array
 * Return: a pointer to the root node of the created BST,
 * or NULL on failure
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t len;

	for (len = 0; len < size; len++)
		bst_insert(&tree, array[len]);

	return (tree);
}
