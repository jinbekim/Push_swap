#include "push_swap.h"

void	node_to_top(t_list **stack, t_list **inst, t_list *node)
{
	int		rev_rot;
	int		rot;

	rev_rot = ft_lstsize(node);
	rot = ft_lstsize(*stack) - rev_rot;
	if (rev_rot < rot)
	{
		while (rev_rot > 0)
		{
			add_instruct_ntimes(inst, "rrb", 1);
			execute_r(NULL, stack, "rrb");
			rev_rot--;
		}
	}
	else
	{
		while (rot > 0)
		{
			add_instruct_ntimes(inst, "rb", 1);
			execute_r(NULL, stack, "rb");
			rot--;
		}
	}
}
