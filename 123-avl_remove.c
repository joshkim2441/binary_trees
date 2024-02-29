#include "binary_trees.h"

/**
 * balance - measures the balance factor of an AVL tree
 * @tree: the tree to go through
 * Return: the balance factor
 */
void balance(avl_t **tree)
{
	int val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	val = binary_tree_balance((const binary_tree_t *)*tree);
	if (val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * inheritor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int inheritor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = inheritor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}
/**
 *avl_remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int avl_remove_type(bst_t *root)
{
	int new_val = 0;
	bst_t *tmp;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_val = inheritor(root->right);
		root->n = new_val;
		return (new_val);
	}
}

/**
 * avl_rem_node - removes a node from an AVL tree
 * @root: a pointer to the root node of the tree
 * for removing a node
 * @value: the value to remove in the tree
 * Return: a pointer to the root node
*/
bst_t *avl_rem_node(bst_t *root, int value)
{
	int tmp = 0;

	if (!root)
		return (root);
	if (value < root->n)
		avl_rem_node(root->left, value);
	else if (value > root->n)
		avl_rem_node(root->right, value);
	else if (value == root->n)
	{
		tmp = avl_remove_type(root);
		if (tmp != 0)
			avl_rem_node(root->right, tmp);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *a_root = (avl_t *) avl_rem_node((bst_t *) root, value);

	if (a_root == NULL)
		return (NULL);
	balance(&a_root);
	return (a_root);
}
