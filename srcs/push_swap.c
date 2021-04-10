#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*astack;
	t_list	*bstack;
	t_list	*tmp;
	int		count;

	bstack = NULL;
	make_stack_list(av, &astack);
	tmp = astack;
	while (tmp)
	{
		count = examine_sort(tmp);
		tmp = tmp->next;
	}
	return (0);
}
