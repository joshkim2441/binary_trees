#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root of the
 * BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on fail
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	bst_t *current = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	current = *tree;
	while (1)
	{
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				break;
			}
		}
		else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				break;
			}
		}
		else
			break;
	}
	return (new_node);
}
