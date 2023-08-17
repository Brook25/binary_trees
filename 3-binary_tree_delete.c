#include "binary_trees.h"

/**
 * find_leaf - finds leaf of a sub tree
 * @node: the root node of the sub tree
 * Return: a leaf node or a node with no left or right nodes
 */

binary_tree_t *find_leaf(binary_tree_t *node)
{
	while (node->left || node->right) {
                if (node->left)
                        node = node->left;
                else if (node->right)
                        node = node->right;
	}
	
	return node;
}

/**
 * binary_tree_delete - deletes a binary tree and frees memory
 * @tree: the tree to be deleted
 * Return: nothing
 */

void binary_tree_delete(binary_tree_t *tree) 
{
	binary_tree_t *sub_t = tree;
	binary_tree_t *parent;
	if (!tree)
		return;
	while (sub_t) {
	sub_t = find_leaf(sub_t);
	parent = sub_t->parent;
	if (parent && parent->left == sub_t)
		parent->left = NULL;
	else if (parent && parent->right == sub_t)
		parent->right = NULL;
	free(sub_t);
	sub_t = parent;
	}
}
