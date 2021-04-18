#include "push_swap.h"

static void	exe_swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	execute_s(t_list **astack, t_list **bstack, char *inst)
{
	if (ft_strncmp("sa", inst, 3) == 0)
		exe_swap(astack);
	else if (ft_strncmp("sb", inst, 3) == 0)
		exe_swap(bstack);
	else if (ft_strncmp("ss", inst, 3) == 0)
	{
		exe_swap(astack);
		exe_swap(bstack);
	}
}
