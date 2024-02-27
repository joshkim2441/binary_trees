#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the tree to traverse
 * @func: a pointer to a function call for each node.
 * the value in the node passed as parameter to this function
 * Return: if tree or func is NULL do nothing
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = binary_tree_height(tree) + 1;
	size_t i;

	if (!tree || !func)
		return;

	for (i = 1; i <= h; i++)
		print_given_level(tree, i, func);
}

/**
 * print_given_level - prints nodes at a given level
 * @tree: a pointer to the root node of the tree to traverse
 * @level: the level to print
 * @func: a pointer to a function call for each node
*/
void print_given_level(const binary_tree_t *tree,
			size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_given_level(tree->left, level - 1, func);
		print_given_level(tree->right, level - 1, func);
	}
}

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

	return ((height_left > height_right) ? height_left : height_right);
}
