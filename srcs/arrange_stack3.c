#include "push_swap.h"

int	find_hold1(t_list **stack, int pivot, int range)
{
	t_list	*tmp;
	int		cnt;

	tmp = *stack;
	cnt = 0;
	while (tmp)
	{
		if (tmp->rank < pivot + range && pivot <= tmp->rank)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	find_hold2(t_list **stack, int pivot, int range)
{
	t_list	*tmp;
	t_list	*fm_btm;

	tmp = *stack;
	fm_btm = NULL;
	while (tmp)
	{
		if (tmp->rank < pivot + range && pivot <= tmp->rank)
			fm_btm = tmp;
		tmp = tmp->next;
	}
	return (ft_lstsize(fm_btm));
}

static int	next_ascending(t_list *tmp, t_list *node, int count)
{
	while (tmp->next != node && tmp->next->rank < node->rank)
	{
		if (tmp->rank < tmp->next->rank)
			count++;
		else
			break ;
		tmp = tmp->next;
	}
	return (count);
}

static t_list	*count_ascending(t_list *node, int *count)
{
	t_list	*tmp;

	(*count) = 1;
	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->rank < tmp->next->rank)
			(*count)++;
		else if (tmp->next->rank < node->rank)
		{
			(*count)++;
			tmp = tmp->next;
			break ;
		}
		else
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int	check_how_many_sorted(t_list *start, t_list *node)
{
	t_list	*last;
	t_list	*tmp;
	int		count;

	last = ft_lstlast(start);
	last->next = start;
	tmp = count_ascending(node, &count);
	count = next_ascending(tmp, node, count);
	last->next = NULL;
	return (count);
}
