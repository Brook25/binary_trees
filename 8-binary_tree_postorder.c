#include "binary_trees.h"

/**
 * traverse_and_print - traverses a tree in post-order traversal
 * and prints the n value of the node
 * @node: the node of the tree where traversal starts
 * Return: node
 */
binary_tree_t *traverse_and_print(binary_tree_t *node)
{
	while (node->left || node->right) {
		if (node->left)
			node = node->left;
		else if (node->right) {
			node = node->right;
		}
	}
	return (node);
}

/**
 * binary_tree_postorder - does post-order traversal and prints n value
 * of node by calling helper functions
 * @tree: tree to be traversed
 * @func: func used to print values
 * Return: None
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *sub_tree;
	if (!(tree && func))
		return;

	sub_tree = (binary_tree_t *) tree;
	sub_tree = traverse_and_print(sub_tree);
	while (sub_tree != tree)
        	{
			func(sub_tree->n);
			if (sub_tree == sub_tree->parent->right)
             		{
                 		sub_tree = sub_tree->parent;
                        	continue;
             		}
              		if (sub_tree == sub_tree->parent->left && !(sub_tree->parent->right))
              		{
				sub_tree = sub_tree->parent;
                        	continue;
                	}

			sub_tree = traverse_and_print(sub_tree->parent->right);
		}
	func(sub_tree->n);
}
