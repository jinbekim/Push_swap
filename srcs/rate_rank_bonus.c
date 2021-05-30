/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rate_rank_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:11:09 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:28:44 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	count_rank(t_list *stack, int num)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (num > *(int *)stack->content)
			count++;
		stack = stack->next;
	}
	return (count);
}

void		rate_rank(t_list *astack)
{
	t_list	*tmp;

	tmp = astack;
	while (tmp)
	{
		tmp->rank = count_rank(astack, *(int *)tmp->content);
		tmp = tmp->next;
	}
}
