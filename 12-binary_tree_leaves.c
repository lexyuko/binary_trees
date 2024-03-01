#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * Description: A NULL pointer is not a leaf
 *
 * Return: number of leaves in a binary tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, L = 0, R = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		L = binary_tree_leaves(tree->left);
		R = binary_tree_leaves(tree->right);
		leaf = L + R;
		return ((!L && !R) ? leaf + 1 : leaf + 0);
	}
}

