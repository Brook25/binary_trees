#include "binary_trees.h"

/**
 * binary_tree_size - calculates no of nodes of a binary tree
 * @tree: tree to be traversed
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	binary_tree_t *sub_tree;
	size_t left_size;
	if (!tree)
		return (0);

	sub_tree = (binary_tree_t *) tree;
	
	left_size = 1 + binary_tree_size(sub_tree->left);
	return left_size + binary_tree_size(sub_tree->right);
}
