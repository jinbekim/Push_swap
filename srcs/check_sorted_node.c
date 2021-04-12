#include "push_swap.h"

static t_list	*count_ascending(t_list *node, int *count, int nodetail)
{
	while ((node->rank < node->next->rank) && node->rank < nodetail)
	{
		(*count) += 1;
		node = node->next;
	}
	return (node->next);
}

int	check_how_many_sorted(t_list *start, t_list *node)
{
	t_list	*last;
	t_list	*tmp;
	int		count;

	count = 1;
	last = ft_lstlast(start);
	last->next = start;
	tmp = count_ascending(node, &count, INT32_MAX);
	if (count == 1 && tmp->next->rank < node->rank)
		count++;
	tmp = count_ascending(tmp, &count, node->rank);
	last->next = NULL;
	return	(count);
}

void	check_longest_sorted_node(t_list *astack)
{
	t_list	*node;

	node = astack;
	while (node)
	{
		node->chunk = check_how_many_sorted(astack, node);
		node = node->next;
	}
}
