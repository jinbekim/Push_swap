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

void	flush_bstack(t_list **astack, t_list **bstack, t_list **inst, int pivot)
{
	int	btm;
	int	flush;

	btm = pivot + ft_lstsize(*bstack) - 1;
	flush = btm;
	while (*bstack)
	{
		if ((*bstack)->rank == pivot)
		{
			add_and_execute_inst(astack, bstack, inst, "pa");
			add_and_execute_inst(astack, bstack, inst, "ra");
			pivot++;
		}
		else if ((*bstack)->rank == btm)
		{
			add_and_execute_inst(astack, bstack, inst, "pa");
			btm--;
		}
		else if (rotation_cost(find_hold1(bstack, pivot, 1), find_hold1(\
		bstack, btm, 1)) > rotation_cost(find_hold2(bstack, pivot, 1) \
		, find_hold2(bstack, btm, 1)))
			add_and_execute_inst(astack, bstack, inst, "rrb");
		else
			add_and_execute_inst(astack, bstack, inst, "rb");
	}
	while (flush-- > btm)
		add_and_execute_inst(astack, bstack, inst, "ra");
}
