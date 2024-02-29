#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of
 * the AVL tree for inserting the value
 * @parent: a pointer to the parent node
 * @n_node: a double pointer to the created node
 * @val: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL on failure
*/

avl_t *val_insert(avl_t **tree, avl_t *parent, avl_t **n_node, int val)
{
	int balance;

	if (*tree == NULL)
		return (*n_node = binary_tree_node(parent, val));
	if ((*tree)->n > val)
	{
		(*tree)->left = val_insert(&(*tree)->left, *tree, n_node, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = val_insert(&(*tree)->right, *tree, n_node, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	// Update balance factor
	balance = binary_tree_balance(*tree);

	if (balance > 1 && (*tree)->left->n > val)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < val)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	val_insert(tree, *tree, &new_node, value);
	return (new_node);
}
