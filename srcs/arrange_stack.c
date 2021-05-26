#include "push_swap.h"

static float	cal_avrg(t_list *stack)
{
	float	sum;
	int		size;

	sum = 0;
	size = ft_lstsize(stack);
	while (stack)
	{
		sum += stack->rank;
		stack = stack->next;
	}
	return (sum / size);
}



void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	while (1)
	{
		//if (topnode == 1)
			//rotate;
			//topnode = 0;
		//else if (topnode / half)
		{
			// push bstack
			// flush bstack;
		}
		// else
			break ;
	}
}
