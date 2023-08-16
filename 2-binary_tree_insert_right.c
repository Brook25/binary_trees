#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts right node into a binary tree
 * @parent: parent node where the new node will be inserted as the right node
 * @value: value of n
 * Return: new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value) {
	binary_tree_t *new_right;
	if (!parent)
		return (NULL);
	new_right = malloc(sizeof(binary_tree_t));
	if (!new_right)
		return (NULL);
	new_right->n = value;
	new_right->left = NULL;
	new_right->parent = parent;
	if (parent->right)
		parent->right->parent = new_right;
	new_right->right = parent->right;
	parent->right = new_right;

	return (new_right);
}
