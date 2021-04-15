#include "push_swap.h"

static void	find_pare(t_list *tmp, char *pare)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp;
	while (tmp2->next && (ft_strncmp((char *)tmp2->content, "rr", 3) == 0 \
	 || ft_strncmp((char *)tmp2->content, "ra", 3) == 0 \
	 || ft_strncmp((char *)tmp2->content, "rb", 3) == 0))
	{
		if (ft_strncmp((char *)tmp2->next->content, pare, 3) == 0)
		{
			((char *)tmp->content)[1] = 'r';
			tmp3 = tmp2->next;
			tmp2->next = tmp3->next;
			free(tmp3->content);
			free(tmp3);
		}
		tmp2 = tmp2->next;
	}
}

void	compression_inst(t_list **inst)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, "ra", 3) == 0)
		{
			find_pare(tmp, "rb");
		}
		else if (ft_strncmp((char *)tmp->content, "rb", 3) == 0)
		{
			find_pare(tmp, "ra");
		}
		tmp = tmp->next;
	}
}
