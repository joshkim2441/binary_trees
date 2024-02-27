#include "binary_trees.h"

/**
 * is_complete - checks if the binary tree is a complete
 * @tree: a pointer to the root node of the tree to check
 * @index: the index of the root node
 * @n_nodes: the number of nodes in the binary tree
 * Return: 1 if tree is complete, 0 otherwise
*/
int is_complete(const binary_tree_t *tree, int index, int n_nodes)
{
	if (!tree)
		return (1);
	if (index >= n_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, n_nodes) &&
		is_complete(tree->right, 2 * index + 2, n_nodes));
}

/**
 * count_nodes - counts the nodes in the binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the number of nodes
*/
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_heap - checks if the tree is a heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a heap, 0 otherwise
*/
int is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right)
		return (tree->n >= tree->left->n);
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_heap(tree->left) && is_heap(tree->right));
	else
		return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree
 * is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid MBH, 0 if not MBH or tree is NULL
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);
	node_count = count_nodes(tree);
	return (is_complete(tree, 0, node_count) && is_heap(tree));
}
