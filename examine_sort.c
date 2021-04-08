#include "push_swap.h"

int	examine_sort(t_list *astack, int ac)
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
	if (count == ac - 1)
		return (0);
	return (-1);
}
