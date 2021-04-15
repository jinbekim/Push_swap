#include "push_swap.h"

static void	add_and_execute_inst(\
t_list **astack, t_list **bstack, t_list **inst, char *instruct)
{
	if (*instruct == 'p')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_p(astack, bstack, instruct);
	}
	else if (*instruct == 'r')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_r(astack, bstack, instruct);
	}
}

void	commence_sort(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	*atop;
	t_list	*btop;
	t_list	*abtm;
	t_list	*bbtm;

	while (*bstack != NULL)
	{
		check_all_sorted_node_cnt(*astack);
		atop = *astack;
		btop = *bstack;
		abtm = ft_lstlast(*astack);
		bbtm = ft_lstlast(*bstack);
		if ((atop->rank > btop->rank && abtm->rank < btop->rank) \
		 || (atop->rank - btop->rank == 1) || btop->rank - abtm->rank == 1)
			add_and_execute_inst(astack, bstack, inst, "pa");
		else if (atop->rank - abtm->rank == 1 || atop->rank == 0)
			add_and_execute_inst(astack, bstack, inst, "ra");
		else if (bbtm->rank < atop->rank && bbtm->rank > abtm->rank)
			add_and_execute_inst(astack, bstack, inst, "rrb");
		else
			add_and_execute_inst(astack, bstack, inst, "rb");
	}
}
