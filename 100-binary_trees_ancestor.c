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
	const binary_tree_t *lcm_anc, *hcm_anc;

	for (lcm_anc = first; lcm_anc; lcm_anc = lcm_anc->parent)
		for (hcm_anc = second; hcm_anc; hcm_anc = hcm_anc->parent)
			if (lcm_anc == hcm_anc)
				return ((binary_tree_t *)lcm_anc);
	return (NULL);
}
