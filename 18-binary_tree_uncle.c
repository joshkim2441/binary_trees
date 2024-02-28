#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the siblings of a node
 * @node: a pointer to the sibling node
 * Return: a pointer to the sibling
 * NULL if node or parent is NULL, or if node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}

/**
 * binary_tree_uncle - finds the uncle of a node:
 * a sibling of the node's parent
 * @node: a pointer to the node to find the uncle
 * Return: a pointer to the uncle node
 * NULL if node is NULL or node has no uncle
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
