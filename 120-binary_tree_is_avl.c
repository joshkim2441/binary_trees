#include "binary_trees.h"
/**
 * height - measures the height of a binary tree
 * @tree: the tree to go through
 * Return: the tree height
 */

size_t height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_height = tree->left ? 1 + height(tree->left) : 1;
			r_height = tree->right ? 1 + height(tree->right) : 1;
		}
		return ((l_height > r_height) ? l_height : r_height);
	}
}

/**
 * balance - compares each subtree if its AVL.
 * @tree: na pointer to the tree to check.
 * @hi: a pointer to the higher node selected
 * @low: a pointer to the lower node selected.
 * Return: 1 if tree is AVL, 0 otherwise.
 */
int balance(const binary_tree_t *tree, int low, int hi)
{
	size_t lft_ht, rt_ht, bal;

	if (tree)
	{
		if (tree->n > hi || tree->n < low)
		{
			return (0);
		}
		lft_ht = height(tree->left);
		rt_ht = height(tree->right);
		bal = lft_ht > rt_ht ? lft_ht - rt_ht : rt_ht - lft_ht;
		if (bal > 1)
		{
			return (0);
		}
		return (balance(tree->left, low, tree->n - 1) &&
			balance(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (balance(tree, INT_MIN, INT_MAX));
}
