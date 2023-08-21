#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves in a tree
 * @tree: tree with no of leaves required
 * Return: no of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves;
	size_t right_leaves;
	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);

	return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
