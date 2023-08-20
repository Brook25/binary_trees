#include "binary_trees.h"

/**
 * binary_tree_depth - function finds depth of a node in a tree
 * @tree: node
 * Return: int value depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *sub_tree;
	int depth = 0;
	if (!tree)
		return 0;
	sub_tree = (binary_tree_t *) tree;
	while (sub_tree->parent)
	{
		depth += 1;
		sub_tree = sub_tree->parent;
	}

	return depth;
}
