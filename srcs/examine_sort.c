#include "push_swap.h"

int	examine_sort(t_list *astack)
{
	int	count;

	count = 1;
	while (astack->next)
	{
		if (*(int *)(astack->content) > *(int *)(astack->next->content))
			break ;
		astack = astack->next;
		count++;
	}
	return (count);
}
