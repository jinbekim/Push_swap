#include "push_swap.h"

static void	rotate_astack(t_list **stack, t_list **inst, int ra, int rra)
{
	while (ra != 0 && rra != 0)
	{
		if (ra < rra)
		{
			add_and_execute_inst(stack, NULL, inst, "ra");
			ra--;
		}
		else
		{
			add_and_execute_inst(stack, NULL, inst, "rra");
			rra--;
		}
	}
}

static void	without_rra(t_list **astack, t_list **bstack, t_list **inst)
{
	while ((*astack)->rank != 0)
	{
		if ((*astack)->rank == ft_lstlast(*astack)->rank + 1)
			add_and_execute_inst(astack, bstack, inst, "ra");
		else if ((*astack)->rank == ft_lstlast(*astack)->rank + 2)
			add_and_execute_inst(astack, bstack, inst, "sa");
		else if ((*astack)->rank == ft_lstlast(*astack)->rank + 3)
			add_and_execute_inst(astack, bstack, inst, "pb");
	}
	if (*bstack)
	{
		add_and_execute_inst(astack, bstack, inst, "pa");
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
}

void	arrange_small_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	while (examine_sort(*astack) != ft_lstsize(*astack))
	{
		if (ft_lstsize(*astack) == 3 || ft_lstsize(*astack) == 2)
		{
			if ((*astack)->rank == 2)
				add_and_execute_inst(astack, bstack, inst, "ra");
			if ((*astack)->rank == 1 && examine_sort(*astack) == 1)
				add_and_execute_inst(astack, bstack, inst, "sa");
			else if (examine_ascending(*astack) == 2)
				add_and_execute_inst(astack, bstack, inst, "rra");
			if ((*astack)->rank == 1 && examine_sort(*astack) == 1)
				add_and_execute_inst(astack, bstack, inst, "sa");
		}
		else
			without_rra(astack, bstack, inst);
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
			pivot += range;
			range /= 2;
		}
	}
	arrange_small_stack(astack, bstack, inst);
}
