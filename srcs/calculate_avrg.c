#include "push_swap.h"

float	calculate_avrg(t_list *stack, int chunk_num)
{
	float	sum;
	int		times;

	sum = 0;
	times = chunk_num;
	if (!stack || !chunk_num)
		return (0);
	while (times--)
	{
		sum += stack->rank;
		stack = stack->next;
	}
	return (sum / chunk_num);
}
