#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *t_right;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	t_right = tree->left;
	tree->left = t_right->right;
	if (t_right->right != NULL)
	{
		t_right->right->parent = tree;
	}
	t_right->right = tree;
	t_right->parent = tree->parent;
	tree->parent = t_right;
	return (t_right);
}
