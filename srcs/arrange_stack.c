#include "push_swap.h"

static t_list	*rotate_astack(t_list **astack, t_list **inst)
{
	t_list	*chunkhead;

	chunkhead = select_chunk(*astack);
	btm_to_btm(astack, inst, chunkhead);
	return (chunkhead);
}

void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	*chunkhead;

	chunkhead = rotate_astack(astack, inst);
	while (check_how_many_sorted(*astack, chunkhead) != ft_lstsize(*astack))
	{
		if ((*astack)->rank == (*astack)->next->rank + 1)
		{
			add_instruct_ntimes(inst, "sa", 1);
			execute_s(astack, bstack, "sa");
		}
		else
		{
			add_instruct_ntimes(inst, "pb", 1);
			execute_p(astack, bstack, "pb");
		}
		chunkhead->chunk = check_how_many_sorted(*astack, chunkhead);
		if (how_many_rot(*astack, find_chunk_btm(*astack, chunkhead)) != 0)
			btm_to_btm(astack, inst, chunkhead);
	}
}
