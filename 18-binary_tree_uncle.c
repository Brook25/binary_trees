#include "binary_trees.h"
/**
 * binary_tree_uncle - finds uncle of a binary tree
 * @node: node to be searched
 * Return: uncle of NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent == node->parent->parent->left)
			return node->parent->parent->right;
		return node->parent->parent->left;
	}

	return NULL;
}

