#include "push_swap.h"

static t_list	*circle_last(t_list *node)
{
	t_list	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

static int	count_ascending(t_list *node)
{
	int		count;
	t_list	*tmp;
	t_list	*node_last;

	count = 1;
	tmp = node;
	node_last = circle_last(node);
	while (tmp != node_last)
	{
		if (tmp->rank < tmp->next->rank)
			count++;
		else if (tmp->rank > tmp->next->rank && tmp->next->rank < node->rank)
		{
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp != node_last)
	{
		if (tmp->rank < tmp->next->rank && tmp->next->rank < node->rank)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_how_many_sorted(t_list *start, t_list *node)
{
	t_list	*last;
	int		count;

	count = 0;
	last = ft_lstlast(start);
	last->next = start;
	count = count_ascending(node);
	last->next = NULL;
	return (count);
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
