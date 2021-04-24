#include "push_swap.h"

static int	count_rank(t_list *stack, int num)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (num > *(int *)stack->content)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	rate_rank(t_list *astack)
{
	t_list	*tmp;

	tmp = astack;
	while (tmp)
	{
		tmp->rank = count_rank(astack, *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	rate_tmp_rank(t_list *astack)
{
	t_list	*tmp;

	tmp = astack;
	while (tmp)
	{
		tmp->tmp_rank = count_rank(astack, *(int *)tmp->content);
		tmp = tmp->next;
	}
}
