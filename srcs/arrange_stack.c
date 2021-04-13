#include "push_swap.h"

static t_list	*find_rank_zero(t_list *topnode)
{
	t_list	*tmp;

	tmp = topnode;
	while (tmp)
	{
		if (tmp->rank == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

static int	rotate_only_left(t_list *stack, int ac)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->chunk != ac - 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*find_chunk_btm(t_list *stack, t_list *chunk_head)
{
	t_list	*tmp;
	t_list	*last;
	int		to_btm;

	tmp = chunk_head;
	to_btm = chunk_head->chunk;
	last = ft_lstlast(stack);
	last->next = stack;
	while (--to_btm > 0)
		tmp = tmp->next;
	last->next = NULL;
	return (tmp);
}

void	btm_to_btm(t_list **stack, t_list **inst, t_list *chunk_head)
{
	t_list	*btm;
	int		stack_size;
	int		rev_rot_cnt;
	int		rot_cnt;

	stack_size = ft_lstsize(*stack);
	btm = find_chunk_btm(*stack, chunk_head);
	rev_rot_cnt = ft_lstsize(btm) - 1;
	rot_cnt = stack_size - rev_rot_cnt;
	if (rev_rot_cnt < rot_cnt)
		add_instruct_ntimes(inst, "rra\n", rev_rot_cnt);
	else
		add_instruct_ntimes(inst, "ra\n", rot_cnt);
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst, int ac)
{
	t_list	*chunk_head;

	chunk_head = find_rank_zero(*astack);
	if (rotate_only_left(*astack, ac))
	{
		btm_to_btm(astack, inst, chunk_head);
		return ;
	}
	if (bstack && inst)
		return ;
}
