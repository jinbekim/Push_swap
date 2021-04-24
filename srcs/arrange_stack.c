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
		if (check_how_many_sorted(*astack, *astack) == ft_lstsize(*astack))
			last_rotate(astack, bstack, inst);
		else if ((*astack)->rank == ft_lstlast(*astack)->rank + 1)
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

static void	arrange_small_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	if (examine_sort(*astack) == ft_lstsize(*astack))
		return ;
	if (ft_lstsize(*astack) == 3 || ft_lstsize(*astack) == 2)
	{
		rate_tmp_rank(*astack);
		if ((*astack)->tmp_rank == 2)
			add_and_execute_inst(astack, bstack, inst, "ra");
		if ((*astack)->tmp_rank == 1 && examine_sort(*astack) == 1)
			add_and_execute_inst(astack, bstack, inst, "sa");
		else if (examine_ascending(*astack) == 2)
			add_and_execute_inst(astack, bstack, inst, "rra");
		if ((*astack)->rank == 1 && examine_sort(*astack) == 1)
			add_and_execute_inst(astack, bstack, inst, "sa");
	}
	else
		without_rra(astack, bstack, inst);
}

static int	to_zero(t_list **astack)
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = *astack;
	while (tmp)
	{
		if (tmp->rank == 0)
			break ;
		cnt++;
		tmp = tmp->next;
	}
	if (cnt <= 3)
		return (0);
	return (cnt / 2);
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
		if (ft_lstsize(*astack) <= 3)
			arrange_small_stack(astack, bstack, inst);
		if (ft_lstsize(*bstack) == range)
		{
			if (pivot != 0)
				while (ft_lstlast(*astack)->rank != pivot - 1)
					add_and_execute_inst(astack, bstack, inst, "rra");
			flush_bstack(astack, bstack, inst, pivot);
			pivot += range;
			range = to_zero(astack);
		}
	}
	arrange_small_stack(astack, bstack, inst);
}
