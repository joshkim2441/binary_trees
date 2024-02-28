#include "binary_trees.h"
/**
 * height - measures the height of the tree
 * @tree: a pointer to the root node of the tree to check
 * Return: the height of the tree
*/
int height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	else
	{
		left_height = tree->left ? 1 + height(tree->left) : 1;
		right_height = tree->right ? 1 + height(tree->right) : 1;
	}
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * balance_factor - finds the balance factor of the binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the balance factor of the binary tree, 0 otherwise
*/
int balance_factor(const binary_tree_t *tree, int low, int hi)
{
	size_t left_ht, right_ht, bal;

	if (!tree)
	{
		if (tree->n > hi || tree->n < low)
		{
			return (0);
		}
		left_ht = height(tree->left);
		right_ht = height(tree->right);
		bal = left_ht > right_ht ? left_ht - right_ht : right_ht - left_ht;
		if (bal > 1)
		{
			return (0);
		}
		return (balance_factor(tree->left, low, tree->n - 1) &&
			balance_factor(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid AVL Tree,
 * 0 otherwise or if the tree is NULL
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (balance_factor(tree, INT_MIN, INT_MAX));
}
