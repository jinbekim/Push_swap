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
			break ;
		}
		tmp2 = tmp2->next;
	}
}

static void	find_pare3(t_list *tmp, char *pare)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp;
	while (tmp2->next && (ft_strncmp((char *)tmp2->content, "rrr", 4) == 0 \
	 || ft_strncmp((char *)tmp2->content, "rra", 4) == 0 \
	 || ft_strncmp((char *)tmp2->content, "rrb", 4) == 0))
	{
		if (ft_strncmp((char *)tmp2->next->content, pare, 4) == 0)
		{
			((char *)tmp->content)[2] = 'r';
			tmp3 = tmp2->next;
			tmp2->next = tmp3->next;
			free(tmp3->content);
			free(tmp3);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	compression_inst(t_list **inst)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *inst;
	prev = NULL;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, "ra", 3) == 0)
			find_pare(tmp, "rb");
		else if (ft_strncmp((char *)tmp->content, "rb", 3) == 0)
			find_pare(tmp, "ra");
		else if (ft_strncmp((char *)tmp->content, "rra", 4) == 0)
			find_pare3(tmp, "rrb");
		else if (ft_strncmp((char *)tmp->content, "rrb", 4) == 0)
			find_pare3(tmp, "rra");
		prev = tmp;
		tmp = tmp->next;
	}
}
