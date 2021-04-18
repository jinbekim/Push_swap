#include "push_swap.h"

int	examine_ascending(t_list *astack)
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

int	examine_sort(t_list *astack)
{
	int	count;

	count = 1;
	if (!astack)
		return (0);
	while (astack->next)
	{
		if (astack->rank + 1 != astack->next->rank)
			break ;
		astack = astack->next;
		count++;
	}
	return (count);
}
