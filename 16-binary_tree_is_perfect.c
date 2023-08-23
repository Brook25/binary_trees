#include "binary_trees.h"
/**
 * binary_tree_is_full_and_complete - check if binary tree is full and all the leaves are at the same level
 * @tree: tree to be checked
 * @level: level of a node
 * @height: height of tree
 * Return: 1 if true else 0
 */
int binary_tree_is_full_and_complete(const binary_tree_t *tree, int level, int height)
{
    if (tree->left && !tree->right)
        return 0;

    if (!tree->left && tree->right)
        return 0;

    if (!tree->left && !tree->right)
    {
        if (level != height)
            return 0;
        return 1;
    }

    return (binary_tree_is_full_and_complete(tree->left, level + 1, height) &&
            binary_tree_is_full_and_complete(tree->right, level + 1, height));
}

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: tree to be checked
 * Return: 1 if perfect else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    int height = 0;
    const binary_tree_t *sub_tree = tree;

    while (sub_tree->left || sub_tree->right)
    {
        if (sub_tree->left)
            sub_tree = sub_tree->left;
        else
            sub_tree = sub_tree->right;
        height++;
    }

    return binary_tree_is_full_and_complete(tree, 0, height);
}

	
