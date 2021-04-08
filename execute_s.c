#include "push_swap.h"

static void	exe_swap(t_list **stack)
{
	t_list	*tmp;
	int		*tmp2;

	tmp = *stack;
	if (tmp->next == NULL)
		return ;
	tmp2 = (int *)tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = tmp2;
}

void	execute_s(t_list **astack, t_list **bstack, t_list *inst)
{
	if (ft_strncmp("sa\n", (char *)inst->content, 3))
		exe_swap(astack);
	else if (ft_strncmp("sb\n", (char *)inst->content, 3))
		exe_swap(bstack);
	else if (ft_strncmp("ss\n", (char *)inst->content, 3))
	{
		exe_swap(astack);
		exe_swap(bstack);
	}
}
