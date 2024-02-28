#include "binary_trees.h"

/**
 * sub_sort - creates tree using the array half element
 * @parent: the parent of the node to be created
 * @arr: the sorted array
 * @start: the start position of the array
 * @end: the end position of the array
 * Return: the created tree
*/
avl_t *sub_sort(avl_t *parent, int *arr, int start, int end)
{
	binary_tree_t *sub;
	avl_t *root;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		sub = binary_tree_node((binary_tree_t *)parent, arr[mid]);
		if (!sub)
			return (NULL);
		root = (avl_t *)sub;
		root->left = sub_sort(root, arr, start, mid - 1);
		root->right = sub_sort(root, arr, mid + 1, end);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: the sorted array
 * @size: the size of the sorted array
 * Return: the AVL tree from the sorted array
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (sub_sort(NULL, array, 0, ((int)(size)) - 1));
}
