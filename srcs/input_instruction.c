#include "push_swap.h"

static int	is_valid_inst(char *inst)
{
	if (ft_strncmp("sa", inst, 3) == 0 \
	 || ft_strncmp("sb", inst, 3) == 0 \
	 || ft_strncmp("ss", inst, 3) == 0 \
	 || ft_strncmp("pa", inst, 3) == 0 \
	 || ft_strncmp("pb", inst, 3) == 0 \
	 || ft_strncmp("ra", inst, 3) == 0 \
	 || ft_strncmp("rb", inst, 3) == 0 \
	 || ft_strncmp("rr", inst, 3) == 0 \
	 || ft_strncmp("rra", inst, 4) == 0 \
	 || ft_strncmp("rrb", inst, 4) == 0 \
	 || ft_strncmp("rrr", inst, 4) == 0)
		return (0);
	return (-1);
}

void	input_instruction(t_list **inst)
{
	char	*instruct;
	int		readline;
	t_list	*new;

	readline = 1;
	while (readline == 1)
	{
		readline = get_next_line(0, &instruct);
		if (readline == 0 && *instruct == '\0')
		{
			free(instruct);
			break ;
		}
		if (is_valid_inst(instruct) == -1)
			error_exit();
		new = ft_lstnew(instruct);
		ft_lstadd_back(inst, new);
	}
}
