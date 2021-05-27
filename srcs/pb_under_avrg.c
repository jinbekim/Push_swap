#include "push_swap.h"

static int	find_target_rra(t_list *stack, float avrg)
{
	t_list	*tmp;

	tmp = NULL;
	while (stack)
	{
		if (stack->rank <= avrg)
			tmp = stack;
		stack = stack->next;
	}
	return (ft_lstsize(tmp));
}

static int	find_target_ra(t_list *stack, float avrg)
{
	int	target;

	target = 0;
	while (stack)
	{
		if (stack->rank <= avrg)
			break ;
		target++;
		stack = stack->next;
	}
	return (target);
}

static void	rotate_minimum(t_list **astack, t_list **inst, int t_ra, int t_rra)
{
	if (t_ra <= t_rra)
	{
		while (t_ra)
		{
			add_and_execute_inst(astack, 0, inst, "ra");
			t_ra--;
		}
	}
	while (t_ra && t_rra)
	{
		add_and_execute_inst(astack, 0, inst, "rra");
		t_rra--;
	}
}

int	pb_under_avrg(t_list **astack, t_list **bstack, t_list **inst, float avrg)
{
	int	t_rra;
	int	t_ra;

	t_rra = find_target_rra(*astack, avrg);
	t_ra = find_target_ra(*astack, avrg);
	while (t_rra != 0)
	{
		rotate_minimum(astack, inst, t_ra, t_rra);
		add_and_execute_inst(astack, bstack, inst, "pb");
		t_ra = find_target_ra(*astack, avrg);
		t_rra = find_target_rra(*astack, avrg);
	}
	return (0);
}
