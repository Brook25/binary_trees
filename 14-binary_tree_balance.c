#include "binary_trees.h"

/**
 * find_height - function calculates the height of a tree
 * @tree: tree to be traversed
 * @height: level of node
 * Return: height
 */
int find_height(binary_tree_t *tree, int level)
{
	int right_height;
	int left_height;

	if (!tree)
		return (0);

	level += 1;
	left_height = find_height(tree->left, level);
	
	right_height = level + find_height(tree->right, level);

	if (left_height >= right_height)
		return left_height;
	return right_height;
}

/**
 * binary_tree_balance - returns the balance factor of a tree
 * @tree: tree to be traversed
 * Return: balnce factor
 */ 
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	return (find_height(tree->left, 0) - find_height(tree->right, 0));
}
