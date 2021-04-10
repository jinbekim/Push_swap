#include "push_swap.h"

void	execute_inst(t_list **astack, t_list **bstack, t_list *inst)
{
	while (inst)
	{
		if (((char *)inst->content)[0] == 's')
			execute_s(astack, bstack, inst->content);
		else if (((char *)inst->content)[0] == 'p')
			execute_p(astack, bstack, inst->content);
		else if (((char *)inst->content)[0] == 'r')
			execute_r(astack, bstack, inst->content);
		inst = inst->next;
	}
}
