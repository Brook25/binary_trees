#include "binary_trees.h"

/**
 * binary_tree_node - creates a new binary tree node.
 * @parent: pointer to the parent node of the node to be created
 * @value: the value of n of the new node
 * Return: pointer to new node or None
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
	binary_tree_t *bt_p = malloc(sizeof(binary_tree_t));
	if (!bt_p)
		return (NULL);

	bt_p->n = value;
    	bt_p->parent = parent;
    	bt_p->left = NULL;
    	bt_p->right = NULL;

    	return (bt_p);
}
