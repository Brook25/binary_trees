#include "binary_trees.h"

/**
 * find_last_node - finds the right most or left most
 *  node in a tree
 *  @root: root node of the tree
 *  Return: left or right most node or null
 */
binary_tree_t *find_last_node(binary_tree_t* root)
{
	binary_tree_t *r = root;
	while(r->right || r->left)
	{
		if (r->right)
			r = r->right;
		else if(r->left)
			r = r->left;
	}
	return r;
}

/**
 * traverse_and_print - traverses a tree in in-order traversal
 * and prints the n value of the node
 * @node: the node of the tree where traversal starts
 * @func: function pointer to print n
 * Return: node
 */
binary_tree_t *traverse_and_print(binary_tree_t *node, void(*func)(int))
{
	while (node->left || node->right) {
		if (node->left)
			node = node->left;
		else if (node->right) {
			func(node->n);
			node = node->right;
		}
	}
	func(node->n);
	return (node);
}

binary_tree_t *find_last_node(binary_tree_t* root);

binary_tree_t *traverse_and_print(binary_tree_t *node, void(*func)(int));

/**
 * binary_tree_preorder - does inorder traversal and prints n value
 * of node by calling helper functions
 * @tree: tree to be traversed
 * @func: func used to print values
 * Return: None
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *sub_tree, *last_node;
	if (!tree)
		return;

	if (!func)
		return;

	sub_tree = (binary_tree_t *) tree;

	last_node = find_last_node(sub_tree);
	sub_tree = traverse_and_print(sub_tree, func);

	while (sub_tree != last_node)
        	{

	     		if (sub_tree == sub_tree->parent->right)
             		{
                 		sub_tree = sub_tree->parent;
                        	continue;
             		}

			func(sub_tree->parent->n);

              		if (sub_tree == sub_tree->parent->left && !(sub_tree->parent->right))
              		{
				sub_tree = sub_tree->parent;
                        	continue;
                	}

			sub_tree = traverse_and_print(sub_tree->parent->right, func);
		}
}
