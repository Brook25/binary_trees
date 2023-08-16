#include "binary_trees.h"

/**
 * binary_tree_node - creates a new binary tree node.
 * parent: pointer to the parent node of the node to be created
 * value: the value of n of the new node
 * Return: pointer to new node or None
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
	binary_tree_t *bt_p = malloc(sizeof(binary_tree_t));
	bt_p->left = NULL;
	bt_p->right = NULL;
	bt_p->n = value;
	bt_p->parent = parent;
	if (parent && !(parent->left))
		parent->left = bt_p;
	else if (parent && parent->left)
		parent->right = bt_p;
	
	return (bt_p);
}
