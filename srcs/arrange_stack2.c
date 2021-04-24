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

static int	rotation_cost(int top, int btm)
{
	int	intersection;

	intersection = 0;
	while (top != 0 && btm != 0)
	{
		top--;
		btm--;
		intersection++;
	}
	return (top + btm + intersection);
}

static void	pivot_handle(\
t_list **astack, t_list **bstack, t_list **inst, int *pivot)
{
	if ((*bstack)->rank == (*pivot))
	{
		add_and_execute_inst(astack, bstack, inst, "pa");
		add_and_execute_inst(astack, bstack, inst, "ra");
		(*pivot)++;
	}
}

void	flush_bstack(t_list **astack, t_list **bstack, t_list **inst, int pivot)
{
	int	btm;
	int	flush;

	btm = pivot + ft_lstsize(*bstack) - 1;
	flush = btm;
	while (*bstack)
	{
		if ((*bstack)->rank == pivot)
			pivot_handle(astack, bstack, inst, &pivot);
		else if ((*bstack)->rank == btm && btm--)
			add_and_execute_inst(astack, bstack, inst, "pa");
		else if (\
		rotation_cost(find_hold1(bstack, pivot, 1), find_hold1(bstack, btm, 1)) > \
		rotation_cost(find_hold2(bstack, pivot, 1), find_hold2(bstack, btm, 1)))
			add_and_execute_inst(astack, bstack, inst, "rrb");
		else
			add_and_execute_inst(astack, bstack, inst, "rb");
	}
	if (check_how_many_sorted(*astack, *astack) == ft_lstsize(*astack))
	{
		last_rotate(astack, bstack, inst);
		return ;
	}
	while (flush-- > btm)
		add_and_execute_inst(astack, bstack, inst, "ra");
}
