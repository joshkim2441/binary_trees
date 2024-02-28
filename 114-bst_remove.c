#include "binary_trees.h"
/**
 * min_value_node - finds the minimum value
 * @root: a pointer to the node with min value
 * Return: a pointer to the node with min value
*/
bst_t *min_value_node(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * where the node will be removed
 * @value: the value to remove from the tree
 * Return: a pointer to the new root node of the
 * tree after removing the desired value
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (!root->left)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (!root->right)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = min_value_node(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
