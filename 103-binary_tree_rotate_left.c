#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *t_right;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	t_right = tree->right;
	tree->right = t_right->left;
	if (t_right->left != NULL)
	{
		t_right->left->parent = tree;
	}
	t_right->left = tree;
	t_right->parent = tree->parent;
	tree->parent = t_right;
	return (t_right);
}
