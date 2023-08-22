#include "binary_trees.h"

/**
 * find_height - function calculates the height of a tree
 * @tree: tree to be traversed
 * @height: level of node
 * Return: height
 */
int get_height(binary_tree_t *tree, int level)
{
	int right_height;
	int left_height;

	if (!tree)
		return (0);

	left_height = get_height(tree->left, level + 1);
	
	right_height = 1 + level + get_height(tree->right, level + 1);

	if (left_height >= right_height)
		return left_height;
	return right_height;
}


int get_height(binary_tree_t *tree, int level);

/**
 * binary_tree_balance - returns the balance factor of a tree
 * @tree: tree to be traversed
 * Return: balnce factor
 */ 
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	
	return (get_height(tree->left, 0) - get_height(tree->right, 0));
}
