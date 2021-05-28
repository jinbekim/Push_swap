#include "push_swap.h"

static int	find_target_rra(t_list *stack, float avrg, int chunk)
{
	t_list	*tmp;

	tmp = NULL;
	while (stack)
	{
		if (stack->chunk_num == chunk && stack->rank <= avrg)
			tmp = stack;
		stack = stack->next;
	}
	return (ft_lstsize(tmp));
}

static int	find_target_ra(t_list *stack, float avrg, int chunk)
{
	int	target;

	target = 0;
	while (stack)
	{
		if (stack->chunk_num == chunk && stack->rank <= avrg)
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

static void	return_stack(t_list **astack, t_list **inst)
{
	t_list	*tmp;
	int		size;
	int		rra;

	tmp = *astack;
	size = ft_lstsize(tmp);
	while (tmp)
	{
		if (tmp->chunk_num == 0)
		{
			while (tmp && tmp->chunk_num == 0)
				tmp = tmp->next;
			rra = ft_lstsize(tmp);
			if (size - rra > rra)
			{
				while (rra--)
					add_and_execute_inst(astack, 0, inst, "rra");
			}
			else
				while (size - rra++)
					add_and_execute_inst(astack, 0, inst, "ra");
			break ;
		}
		tmp = tmp->next;
	}
}

int	pb_under_avrg(t_list **astack, t_list **bstack, t_list **inst, float avrg)
{
	int	t_rra;
	int	t_ra;
	int	chunk;

	chunk = (*astack)->chunk_num;
	t_rra = find_target_rra(*astack, avrg, chunk);
	t_ra = find_target_ra(*astack, avrg, chunk);
	while (t_rra != 0)
	{
		rotate_minimum(astack, inst, t_ra, t_rra);
		add_and_execute_inst(astack, bstack, inst, "pb");
		t_ra = find_target_ra(*astack, avrg, chunk);
		t_rra = find_target_rra(*astack, avrg, chunk);
	}
	return_stack(astack, inst);
	return (0);
}
