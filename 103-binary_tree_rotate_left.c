#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *t_left;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	t_left = tree->left;
	tree->left = t_left->left;
	if (t_left->left != NULL)
	{
		t_left->left->parent = tree;
	}
	t_left->left = tree;
	t_left->parent = tree->parent;
	tree->parent = t_left;
	return (t_left);
}
