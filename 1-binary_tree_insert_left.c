#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child
 * @parent: parent node
 * @value: value of the inserted node
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
	binary_tree_t *new_left = malloc(sizeof(binary_tree_t));
	if (!new_left || !parent)
		return (NULL);
	new_left->n = value;
	new_left->parent = parent;
	new_left->right = NULL;
	new_left->left = parent->left;
	parent->left = new_left;
	if (new_left->left)
		new_left->left->parent = new_left;

	return (new_left);
}
