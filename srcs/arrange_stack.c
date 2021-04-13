#include "push_swap.h"

static int	is_arranged(t_list *stack, int ac)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk != ac - 1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst, int ac)
{
}
