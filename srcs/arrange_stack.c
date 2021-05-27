#include "push_swap.h"

static void	is_need_swap(t_list **stack, t_list **inst)
{
	if ((*stack)->rank > ((*stack)->next->rank))
		add_and_execute_inst(stack, 0, inst, "sa");
	init_chunk_num(*stack, 1);
	init_chunk_num((*stack)->next, 1);
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	float	avrg;

	init_chunk_num(*astack, ft_lstsize(*astack));
	while ((*astack)->chunk_num != 0)
	{
		avrg = calculate_avrg(*astack, (*astack)->chunk_num);
		if ((*astack)->chunk_num > 2)
		{
			pb_under_avrg(astack, bstack, inst, avrg);
			init_chunk_num(*astack, ft_lstsize(*astack));
			pa_over_avrg(astack, bstack, inst);
		}
		else if ((*astack)->chunk_num == 1)
		{
			init_chunk_num(*astack, 0);
			add_and_execute_inst(astack, bstack, inst, "ra");
		}
		else if ((*astack)->chunk_num == 2)
			is_need_swap(astack, inst);
	}
}
