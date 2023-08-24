#include "binary_trees.h"
/**
 * binary_tree_sibling - finds sibling of a node
 * @node: node to be checked
 * Return: sibling if found else NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node == node->parent->left)
			return node->parent->right;
		return node->parent->left;
	}

	return NULL;
}
