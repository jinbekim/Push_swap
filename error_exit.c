#include "push_swap.h"

void	error_exit(t_list **ptr)
{
	ft_lstclear(ptr, free);
	write(2, "Error\n", 7);
	exit(0);
}
