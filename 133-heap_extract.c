#include "binary_trees.h"

/**
 * find_last_node - finds the last node in the heap
 * @root: a pointer to the root node of the tree
 * Return: the last node
*/
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[100];
	int rear = -1, front = 0;

	queue[++rear] = root;

	while (front <= rear)
	{
		heap_t *curr = queue[front++];

		if (curr->left)
			queue[++rear] = curr->left;
		if (curr->right)
			queue[++rear] = curr->right;
	}
	return (queue[rear]);
}

/**
 * sift_down - sifts down a node in the heap
 * @node: a pointer to the node to be sifted down
 * Return: the sifted down node
*/
void sift_down(heap_t *node)
{
	heap_t *largest;

	while (1)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		swap(node, largest);
		node = largest;
	}
}

/**
 * heap_extract - extracts the root of a Max Binary Heap
 * @root: a double pointer to the root node of the heap
 * Return: the value stored in the root node, 0 otherwise
*/
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int root_value;

	if (!root || !*root)
		return (0);
	last_node = find_last_node(*root);
	root_value = (*root)->n;

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;

		(*root)->n = last_node->n;
		free(last_node);

		sift_down(*root);
	}
	return (root_value);
}
