#include "binary_trees.h"
/**
 * check_sub_tree_Left - check if all nodes are smaller than
 * the root specified
 * @node: node in the tree to verify condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int l = 0, r = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		l = check_sub_tree_l(node->left, max);
		r = check_sub_tree_l(node->right, max);
		if (l == r && l == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_right - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_right(const binary_tree_t *node, int min)
{
	int l = 0, r = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		l = check_sub_tree_r(node->left, min);
		r = check_sub_tree_r(node->right, min);
		if (l == r && l == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a bst or not
 * the process here is first verify that the left node be smaller than the root
 * then verify if the r node is bigger than th root.
 * after that verify if the left subtree has nodes smaller than root
 * and the r subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, l = 2, r = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_left(tree->left, tree->n);
		if (var == 0)
			return (0);
		l = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_right(tree->right, tree->n);
		if (var == 0)
			return (0);
		r = binary_tree_is_bst(tree->right);
	}
	if (l != 2 || r != 2)
	{
		if (l == 0 || r == 0)
			return (0);
	}
	return (1);
}
