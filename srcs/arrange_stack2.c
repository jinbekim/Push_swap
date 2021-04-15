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

t_list	*select_chunk(t_list *astack)
{
	t_list	*longest;
	t_list	*tmp;

	tmp = astack;
	longest = tmp;
	if (astack->chunk == ft_lstsize(astack))
		return (find_rank_zero(astack));
	while (tmp)
	{
		if (longest->chunk < tmp->chunk)
			longest = tmp;
		else if (longest->chunk == tmp->chunk && \
		 (how_many_rot(astack, find_chunk_btm(astack, longest)) \
		 > how_many_rot(astack, find_chunk_btm(astack, tmp))))
			longest = tmp;
		tmp = tmp->next;
	}
	return (longest);
}

int	how_many_rot(t_list *stack, t_list *chunktail)
{
	int	rev_rot;
	int	rot;

	rev_rot = ft_lstsize(chunktail) - 1;
	rot = ft_lstsize(stack) - rev_rot;
	if (rev_rot < rot)
		return (rev_rot);
	return (rot);
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
	int		rev_rot;
	int		rot;

	btm = find_chunk_btm(*stack, chunk_head);
	rev_rot = ft_lstsize(btm) - 1;
	rot = ft_lstsize(*stack) - rev_rot;
	if (rev_rot < rot)
	{
		while (rev_rot > 0)
		{
			add_instruct_ntimes(inst, "rra", 1);
			execute_r(stack, NULL, "rra");
			rev_rot--;
		}
	}
	else
	{
		while (rot > 0)
		{
			add_instruct_ntimes(inst, "ra", 1);
			execute_r(stack, NULL, "ra");
			rot--;
		}
	}
}
