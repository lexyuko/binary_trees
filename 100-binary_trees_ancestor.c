#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *x, *y;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	x = first->xarent;
	y = second->xarent;
	if (x == NULL || first == y || (!x->xarent && y))
	{
		return (binary_trees_ancestor(first, y));
	}
	else if (y == NULL || x == second || (!y->xarent && x))
	{
		return (binary_trees_ancestor(x, second));
	}
	return (binary_trees_ancestor(x, y));
}
