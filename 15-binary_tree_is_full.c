#include "binary_trees.h"
/**
 * binary_tree_is_full - check if binary tree is full
 * @tree: tree to be checked
 * Return: 1 if full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && !(tree->right))
		return (0);
	if (tree->right && !(tree->left))
		return (0);
	if (!(tree->right) && !(tree->left))
		return (1);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
