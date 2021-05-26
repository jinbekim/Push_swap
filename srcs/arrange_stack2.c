#include "push_swap.h"

void	last_rotate(t_list **astack, t_list **bstack, t_list **inst)
{
	int		btmrank;
	t_list	*btm;

	btmrank = ft_lstsize(*astack);
	btm = *astack;
	while (btm)
	{
		if (btm->rank == btmrank)
			break ;
		btm = btm->next;
	}
	if (ft_lstsize(btm) > (ft_lstsize(*astack) - ft_lstsize(btm)))
		while ((*astack)->rank != 0)
			add_and_execute_inst(astack, bstack, inst, "ra");
	else
		while ((*astack)->rank != 0)
			add_and_execute_inst(astack, bstack, inst, "rra");
}

static void	pivot_handle(\
t_list **astack, t_list **bstack, t_list **inst, int *pivot)
{
	add_and_execute_inst(astack, bstack, inst, "pa");
	if (ft_lstsize(*bstack) != 0)
		add_and_execute_inst(astack, bstack, inst, "ra");
	(*pivot)++;
}