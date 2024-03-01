#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *turns;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	turns = tree->right;
	tree->right = turns->left;
	if (turns->left != NULL)
	{
		turns->left->parent = tree;
	}
	turns->left = tree;
	turns->parent = tree->parent;
	tree->parent = turns;
	return (turns);
}
