#include "push_swap.h"

static void	exe_rotate(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

static void	exe_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*stack)->next == NULL)
		return ;
	tmp = ft_lstlast((*stack));
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(stack, tmp);
}

void	execute_r(t_list **astack, t_list **bstack, t_list *inst)
{
	if (ft_strncmp("ra\n", (char *)inst->content, 3))
		exe_rotate(astack);
	else if (ft_strncmp("rb\n", (char *)inst->content, 3))
		exe_rotate(bstack);
	else if (ft_strncmp("rr\n", (char *)inst->content, 3))
	{
		exe_rotate(astack);
		exe_rotate(bstack);
	}
	else if (ft_strncmp("rra\n", (char *)inst->content, 4))
		exe_reverse_rotate(astack);
	else if (ft_strncmp("rrb\n", (char *)inst->content, 4))
		exe_reverse_rotate(bstack);
	else if (ft_strncmp("rrr\n", (char *)inst->content, 4))
	{
		exe_reverse_rotate(astack);
		exe_reverse_rotate(bstack);
	}
}
