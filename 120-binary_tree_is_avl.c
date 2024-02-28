#include "binary_trees.h"
/**
 * height - measures the height of the tree
 * @tree: a pointer to the root node of the tree to check
 * Return: the height of the tree
*/
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * balance_factor - finds the balance factor of the binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the balance factor of the binary tree, 0 otherwise
*/
int balance_factor(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->left) - height(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid AVL Tree,
 * 0 otherwise or if the tree is NULL
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);
	balance = balance_factor(tree);
	if (balance > 1 || balance < -1)
		return (0);
	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}
