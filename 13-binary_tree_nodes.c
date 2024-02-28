#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at
 * least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree
 * to count the number of nodes
 * Return: the number of nodes, if tree is NULL, return 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		nodes + ((tree->left || tree->right) ? 1 : 0);
		nodes = binary_tree_nodes(tree->left);
		nodes = binary_tree_nodes(tree->right);
		return (nodes);
	}
}
