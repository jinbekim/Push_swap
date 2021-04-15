#include "push_swap.h"

int	examine_sort(t_list *astack)
{
	int	count;

	count = 1;
	if (!astack)
		return (0);
	while (astack->next)
	{
		if (astack->rank > astack->next->rank)
			break ;
		astack = astack->next;
		count++;
	}
	return (count);
}
