#include "binary_trees.h"
/**
 * binary_tree_insert_right - Insert node as right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: value to store in created node
 * Return: a pointer to the new node, or NULL on fail or if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;

	if (new_node->right)
		new_node->right->parent = new_node;

	parent->right = new_node;

	return (new_node);
}
