/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:09:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:17:37 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	exe_swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

void		execute_s(t_list **astack, t_list **bstack, char *inst)
{
	if (ft_strncmp("sa", inst, 3) == 0)
		exe_swap(astack);
	else if (ft_strncmp("sb", inst, 3) == 0)
		exe_swap(bstack);
	else if (ft_strncmp("ss", inst, 3) == 0)
	{
		exe_swap(astack);
		exe_swap(bstack);
	}
}
