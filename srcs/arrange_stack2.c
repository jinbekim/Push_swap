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

void	rotate_astack(t_list **stack, t_list **inst, int ra, int rra)
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
