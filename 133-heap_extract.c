#include "binary_trees.h"
#include <stdlib.h>

/**
 * t_height - measures a binary trees' height
 * @tree: a pointer to the root node of the
 * tree to measure the height
 * Return: the tree height, 0 if tree is NULL
*/
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

/**
 * t_hsize - measures the height sum of the tree
 * @tree: a pointer tot the root node of the tree
 * Return: the tree size, 0 otherwise
*/
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

/**
 * preord_trv - goes throgh a binary tree in preorder
 * traversal
 * @root: a pointer to the root of the tree to traverse
 * @lnode: the last node to traverse
 * @ht: the tree height
 * Return: none
*/
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

/**
 * bry_heapify - function to heapify a Max Binary Heap
 * @tree: a pointer to the Max Binary Heap
*/
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
 * Return: the value of the ectracted node, 0 otherwise
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
