#include "push_swap.h"

static void	is_need_swap(t_list **stack, t_list **inst)
{
	if ((*stack)->rank > ((*stack)->next->rank))
		add_and_execute_inst(stack, 0, inst, "sa");
	init_chunk_num(*stack, 1);
	init_chunk_num((*stack)->next, 1);
}

static void	init_rest_chunk(t_list *stack)
{
	int		head;
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = stack;
	head = stack->chunk_num;
	if (head == 0)
		return ;
	while (tmp && tmp->chunk_num == head)
	{
		size++;
		tmp = tmp->next;
	}
	while (stack && stack->chunk_num == head)
	{
		stack->chunk_num = size;
		stack = stack->next;
	}
}

static void	without_rra(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	*tmp;

	tmp = *astack;
	if (tmp->rank > tmp->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "pb");
	is_need_swap(astack, inst);
	if ((*astack)->chunk_num == 1)
	{
		init_chunk_num(*astack, 0);
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
	add_and_execute_inst(astack, bstack, inst, "pa");
	is_need_swap(astack, inst);
	while ((*astack)->chunk_num == 1)
	{
		init_chunk_num(*astack, 0);
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
}

static void	small_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	**t;

	t = astack;
	init_chunk_num((*t), 0);
	init_chunk_num((*t)->next, 0);
	init_chunk_num((*t)->next->next, 0);
	if (ft_lstsize(*t) != 3)
		return (without_rra(astack, bstack, inst));
	if ((*t)->rank > (*t)->next->rank && (*t)->rank > (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "ra");
	if ((*t)->next->rank > (*t)->rank \
	 && (*t)->next->rank > (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "rra");
	if ((*t)->rank > (*t)->next->rank && (*t)->rank < (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "sa");
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	float	avrg;

	init_chunk_num(*astack, ft_lstsize(*astack));
	while ((*astack)->chunk_num != 0)
	{
		avrg = calculate_avrg(*astack, (*astack)->chunk_num);
		if ((*astack)->chunk_num > 3)
		{
			pb_under_avrg(astack, bstack, inst, avrg);
			init_rest_chunk(*astack);
			pa_over_avrg(astack, bstack, inst);
		}
		if ((*astack)->chunk_num == 1)
		{
			init_chunk_num(*astack, 0);
			add_and_execute_inst(astack, bstack, inst, "ra");
		}
		else if ((*astack)->chunk_num == 2)
			is_need_swap(astack, inst);
		else if ((*astack)->chunk_num == 3)
			small_stack(astack, bstack, inst);
	}
}
