#include "binary_trees.h"

/**
 * heap_bal - swaps the values of two nodes
 * @a: a pointer to the first node
 * @b: a pointer to the second node
 * Return: the swapped nodes
*/
heap_t *heap_bal(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
	return (b);
}

/**
 * tree_size - measures the size of the tree
 * @root: a pointer to the root
 * Return: the tree size, 0 otherwise
*/
size_t tree_size(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + tree_size(root->left) + tree_size(root->left));
}

/**
 * find_heap_node - performs level order traversal
 * until an empty spot is found
 * @root: a pointer to the root node
 * @node: a pointer to the spot to insert node
 * Return: the empty spot
*/
heap_t *find_heap_node(heap_t *root, size_t node)
{
	size_t prt, chd;

	if (node == 0)
		return (root);
	prt = (node - 1) / 2;
	chd = (node - 1) % 2;

	if (chd == 0)
		return (find_heap_node(root, prt)->left);
	return (find_heap_node(root, prt)->right);
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: a double-pointer to the root of the node
 * of the heap to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	int swap = 1;
	heap_t *n_node, *parent;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		n_node = binary_tree_node(NULL, value);
		*root = n_node;
		return (n_node);
	}

	size = tree_size(*root);
	parent = find_heap_node(*root, (size - 1) / 2);
	n_node = binary_tree_node(parent, value);
	if (size % 2 == 1)
		parent->left = n_node;
	else
		parent->right = n_node;
	if (n_node == NULL)
		return (NULL);

	while (swap == 1 && parent != NULL)
	{
		if (parent->n >= n_node->n)
			swap = 0;
		else
		{
			n_node = heap_bal(n_node, parent);
			parent = n_node->parent;
		}
	}

	return (n_node);
}
