#include "push_swap.h"

void	make_stack_a(char **av, t_list **astack)
{
	int		i;
	int		*tmp;
	t_list	*new;

	i = 0;
	while (av[++i])
	{
		tmp = malloc(sizeof(int));
		if (tmp == NULL)
			error_exit(astack);
		*tmp = ft_atoi(av[i]);
		if (*tmp == -1 && av[i][0] != '-')
			error_exit(astack);
		if (*tmp == 0 && (av[i][0] != '0' || av[i][0] != '+'))
			error_exit(astack);
		new = ft_lstnew(tmp);
		ft_lstadd_back(astack, new);
	}
}
