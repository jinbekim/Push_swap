#include "push_swap.h"

static int	is_valid_inst(char *inst)
{
	if (ft_strncmp("sa\n", inst, 3) == 0 \
	 || ft_strncmp("sb\n", inst, 3) == 0 \
	 || ft_strncmp("ss\n", inst, 3) == 0 \
	 || ft_strncmp("pa\n", inst, 3) == 0 \
	 || ft_strncmp("pb\n", inst, 3) == 0 \
	 || ft_strncmp("ra\n", inst, 3) == 0 \
	 || ft_strncmp("rb\n", inst, 3) == 0 \
	 || ft_strncmp("rr\n", inst, 3) == 0 \
	 || ft_strncmp("rra\n", inst, 4) == 0 \
	 || ft_strncmp("rrb\n", inst, 4) == 0 \
	 || ft_strncmp("rrr\n", inst, 4) == 0)
		return (0);
	return (-1);
}

void	make_inst_list(t_list **inst)
{
	char	*instruct;
	int		readline;
	t_list	*new;

	while (1)
	{
		readline = get_next_line(0, &instruct);
		if (readline == 0)
		{
			free(instruct);
			break ;
		}
		if (is_valid_inst(instruct) == -1)
		{
			free(instruct);
			error_exit(inst);
		}
		new = ft_lstnew(instruct);
		ft_lstadd_back(inst, new);
		free(instruct);
	}
}
