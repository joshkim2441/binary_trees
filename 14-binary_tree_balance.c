#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of tree to measure height
 * Return: height of the tree, if tree is NULL return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
 * binary_tree_balance - measures the balance factor
 * of a bianry tree
 * @tree: a pointer to the root node of the tree
 * to measure the balance factor
 * Return: balance factor, if tree is NULL, return 0
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h  = 0, right_h = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height(tree->right);

	return (left_h - right_h);
}
