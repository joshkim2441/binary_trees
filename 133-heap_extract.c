#include "binary_trees.h"
#include <stdlib.h>

size_t t_height(const heap_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_ht = 1 + t_height(tree->left);
	if (tree->right)
		right_ht = 1 + t_height(tree->right);
	if (left_ht > right_ht)
		return (left_ht);
	return (right_ht);
}

size_t t_hsize(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_ht = 1 + t_hsize(tree->left);
	if (tree->right)
		right_ht = 1 + t_hsize(tree->right);
	return (left_ht + right_ht);
}

void preord_trv(heap_t *root, heap_t **lnode, size_t ht)
{
	if (!root)
		return;
	if (!ht)
		*lnode = root;
	ht--;

	preord_trv(root->left, lnode, ht);
	preord_trv(root->right, lnode, ht);
}

void bry_heapify(heap_t *tree)
{
	heap_t *t1, *t2;
	int val;

	if (!tree)
		return;
	t1 = tree;

	while (1)
	{
		if (!t1->left)
			break;
		if (!t1->right)
			t2 = t1->left;
		else
		{
			if (t1->left->n > t1->right->n)
				t2 = t1->left;
			else
				t2 = t1->right;
		}
		if (t1->n > t2->n)
			break;
		val = t1->n;
		t1->n = t2->n;
		t2->n = val;
		t1 = t2;
	}
}

/**
 * heap_extract - extracts the root of a Max Binary Heap
 * @root: a double pointer to the root node of the heap
 * Return: the value stored in the root node, 0 otherwise
*/
int heap_extract(heap_t **root)
{
	heap_t *mx_heap, *last_node;
	int root_value;

	if (!root || !*root)
		return (0);
	mx_heap = *root;
	root_value = mx_heap->n;

	if (!mx_heap->left && !mx_heap->right)
	{
		*root = NULL;
		free(mx_heap);
		return (root_value);
	}
	preord_trv(mx_heap, &last_node, t_height(mx_heap));

	mx_heap->n = last_node->n;
	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	free(last_node);
	bry_heapify(mx_heap);
	*root = mx_heap;
	return (root_value);
}
