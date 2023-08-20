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
 * find_height - traverses a tree in post-order traversal
 * and prints the n value of the node
 * @node: the node of the tree where traversal starts
 * Return: node
 */
size_t find_height(binary_tree_t **node)
{
	int no_of_paths = 0;
	while ((*node)->left || (*node)->right) {
		if ((*node)->left)
			*node = (*node)->left;
		else if ((*node)->right) {
			*node = (*node)->right;
		}
		no_of_paths += 1;
	}
	//printf("%d\n", no_of_paths);
	return no_of_paths;
}

/**
 * binary_tree_height - does post-order traversal and prints n value
 * of node by calling helper functions
 * @tree: tree to be traversed
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *sub_tree, *last_node;
	int level, height;
	if (!tree)
		return 0;

	sub_tree = (binary_tree_t *) tree;
	last_node = find_last_node(sub_tree);
	height = level = find_height(&sub_tree);
	while (sub_tree != tree && sub_tree != last_node)
        	{
			if (sub_tree == sub_tree->parent->right)
             		{
                 		sub_tree = sub_tree->parent;
				level -= 1;
                        	continue;
             		}
              		if (sub_tree == sub_tree->parent->left && !(sub_tree->parent->right))
              		{
				sub_tree = sub_tree->parent;
				level -= 1;
                        	continue;
                	}

			sub_tree = sub_tree->parent->right;
			level += find_height(&sub_tree);
			//printf("%d\n", level);
			if (level > height)
				height = level;
		}
	return height;
}
