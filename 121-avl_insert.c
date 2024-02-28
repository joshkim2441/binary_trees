#include "binary_trees.h"

/**
 * avl_insert_node - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of
 * the AVL tree for inserting the value
 * @parent: a pointer to the parent node
 * @new_node: a double pointer to the created node
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL on failure
*/

avl_t *avl_insert_node(avl_t **tree, avl_t *parent,
			avl_t **new_node, int value)
{
	int balance;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_node(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_node(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	balance = binary_tree_balance(*tree);
	if (balance > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > value)
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
	avl_insert_node(tree, *tree, &new_node, value);
	return (new_node);
}
