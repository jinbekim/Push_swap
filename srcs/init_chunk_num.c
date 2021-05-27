#include "push_swap.h"

void	init_chunk_num(t_list *stack, int size)
{
	int	times;

	times = size;
	if (size == 0)
		times = 1;
	while (times--)
	{
		stack->chunk_num = size;
		stack = stack->next;
	}
}
