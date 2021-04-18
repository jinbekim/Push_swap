#include "push_swap.h"

void	add_and_execute_inst(\
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
	else if (*instruct == 's')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_s(astack, bstack, instruct);
	}
}
