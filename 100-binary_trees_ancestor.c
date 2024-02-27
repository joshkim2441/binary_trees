#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes:
 * the deepest node that has both nodes as descendants.
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor
 * node of the two given nodes, NULL if no common ancestor found
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *mover = (binary_tree_t *)first;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		first = first->parent;
		second = mover;
	}
	return (NULL);
}
