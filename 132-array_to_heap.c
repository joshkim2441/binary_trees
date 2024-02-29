#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap from an array
 * @array: a pointer to the first element of the
 * array to be converted
 * @size: the number of elements in the array
 * Return: a pointer to the root node of the
 * created binary heap, or NULL on failure
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t j;

	if (!array)
		return (NULL);

	root = heap_insert(&root, array[0]);

	for (j = 0; j < size; j++)
		heap_insert(&root, array[j]);
	return (root);
}
