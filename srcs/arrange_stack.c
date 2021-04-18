#include "push_swap.h"

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
		if ((*bstack)->rank == btm)
		{
			add_and_execute_inst(astack, bstack, inst, "pa");
			btm--;
		}
		if (rotation_cost(find_hold1(bstack, pivot, 1), find_hold1(\
		bstack, btm, 1)) > rotation_cost(find_hold2(bstack, pivot, 1) \
		, find_hold2(bstack, btm, 1)))
			add_and_execute_inst(astack, bstack, inst, "rrb");
		else
			add_and_execute_inst(astack, bstack, inst, "rb");
	}
	while ((*astack)->rank >= flush)
		add_and_execute_inst(astack, bstack, inst, "ra");
}

void	arrange_small_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	while (examine_sort(*astack) != ft_lstsize(*astack))
	{
		if (ft_lstsize(*astack) == 3 || ft_lstsize(*astack) == 2)
		{

		}
		else
		{

		}
	}
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	int		range;
	int		pivot;

	pivot = 0;
	range = ft_lstsize(*astack) / 2;
	while (range > 1)
	{
		if ((*astack)->rank < pivot + range && (*astack)->rank >= pivot)
			add_and_execute_inst(astack, bstack, inst, "pb");
		else
			rotate_astack(astack, inst, \
			find_hold1(astack, pivot, range), find_hold2(astack, pivot, range));
		if (ft_lstsize(*bstack) == range)
		{
			flush_bstack(astack, bstack, inst, pivot);
			range /= 2;
			pivot += range;
		}
	}
	arrange_small_stack(astack, bstack, inst);
}
