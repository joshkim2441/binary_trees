#include "binary_trees.h"
/**
 * binary_tree_is_bst - checks if a binary tree is
 * a valid bst (Binary Search Tree)
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 if tree is not BST or NULL
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (bst_helper((binary_tree_t *)tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - a helper function for binary_tree_is_bst
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value that the current node can take
 * @max: the maximum value that the current node can take
 * Return: 1 if tree is a valid BST, otherwise 0
*/
int bst_helper(binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (bst_helper(tree->left, min, tree->n - 1) &&
		bst_helper(tree->right, tree->n + 1, max));
}
