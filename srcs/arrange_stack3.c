#include "push_swap.h"

static int	find_fm_top(t_list *stack, float evrg)
{
	
}


int	find_hold(t_list **stack, float evrg)
{
	int	fm_top;
	int	fm_btm;

	fm_btm = find_fm_top(*stack, evrg);
	fm_top = find_fm_btm(*stack, evrg);
	if (fm_btm > fm_top)
}
