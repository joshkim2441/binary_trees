#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the size of the tree, if tree is NULL, return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_ht = 1 + binary_tree_size(tree->left);
	if (tree->right)
		right_ht = 1 + binary_tree_size(tree->right);

	return (left_ht + right_ht);
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
	int j, *arr = NULL;

	if (!heap || !size)
		return (NULL);
	*size = binary_tree_size(heap) + 1;

	arr = malloc(*size * sizeof(int));

	if (!arr)
		return (NULL);

	for (j = 0; heap; j++)
	{
		arr[j] = heap_extract(&heap);
	}
	return (arr);
}
