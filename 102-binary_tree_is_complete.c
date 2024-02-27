#include "binary_trees.h"
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is complete, if tree is NULL return 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0, nodes = 0;

	if (!tree)
		return (0);

	nodes = count_nodes(tree);

	return (is_complete(tree, index, nodes));
}

/**
 * count_nodes - counts the number of nodes in a binary tree
 * @tree: a pointer to the root node of the tree to
 * count the number of nodes
 * Return: the number of nodes in the tree
*/
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) +
		count_nodes(tree->right));
}

/**
 * is_complete - checks if a binary tree is complete if all levels
 * are completely filled except posibly for the last level,
 * which is filled from left to right.
 * @tree: a pointer to the root node of the tree to check
 * @index: the index of the current node
 * @nodes: the total number of nodes in the tree
 * Return: 1 if tree is complete, otherwise 0
*/
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}
