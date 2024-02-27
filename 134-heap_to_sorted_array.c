#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the size of the tree, if tree is NULL, return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array
 * @heap: a pointer to the root of the heap to convert
 * @size: an address to store the size of the array
 * Return: sorted array in descending order
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	*size = binary_tree_size(heap);
	size_t i;

	int *array = malloc(*size * sizeof(int));

	if (!array)
		return (NULL);

	for (i = 0; i < *size; i++)
	{
		array[i] = heap_extract(&heap);
	}
	return (array);
}
