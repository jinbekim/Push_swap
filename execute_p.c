#include "push_swap.h"

static void	exe_push(t_list **to, t_list **from)
{
	if ((*from)->content == NULL)
		return ;
	ft_lstadd_front(to, (*from));
	*from = (*from)->next;
}

void	execute_p(t_list **astack, t_list **bstack, t_list *inst)
{
	if (ft_strncmp("pa\n", (char *)inst->content, 3))
		exe_push(astack, bstack);
	else if (ft_strncmp("pb\n", (char *)inst->content, 3))
		exe_push(bstack, astack);
}
