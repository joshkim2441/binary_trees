#include "binary_trees.h"

/**
 * create_node - creates a node with a given value
 * @value: the value to be stored in the created node
 * Return: a pointer to the new node
*/
heap_t *create_node(int value)
{
	heap_t *node = malloc(sizeof(heap_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->parent = node->left = node->right = NULL;
	return (node);
}

/**
 * swap - swaps the values of two nodes
 * @a: a pointer to the first node
 * @b: a pointer to the second node
 * Return: the swapped nodes
*/
void swap(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * sift_up - sifts up a node in the heap
 * @node: the node to be sifted up
 * Return: the sifted up node
*/
void sift_up(heap_t *node)
{
	while (node->parent && node->parent->n < node->n)
	{
		swap(node, node->parent);
		node = node->parent;
	}
}

/**
 * level_order_insert - performs level order traversal
 * until an empty spot is found
 * @root: a pointer to the root node
 * @node: a pointer to the spot to insert node
 * Return: the empty spot
*/
heap_t *level_order_insert(heap_t *root, heap_t *node)
{
	heap_t *queue[100];
	int rear = -1, front = 0;

	queue[++rear] = root;

	while (front <= rear)
	{
		heap_t *curr = queue[front++];

		if (!curr->left)
		{
			curr->left = node;
			node->parent = curr;
			return (node);
		}
		else if (!curr->right)
		{
			curr->right = node;
			node->parent = curr;
			return (node);
		}
		queue[++rear] = curr->left;
		queue[++rear] = curr->right;
	}
	return (NULL);
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
	heap_t *node = create_node(value);

	if (!node)
		return (NULL);
	if (!*root)
	{
		*root = node;
	}
	else
	{
		node = level_order_insert(*root, node);
		sift_up(node);
	}
	return (node);
}
