#include "push_swap.h"

static void	init_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	*astack = NULL;
	*bstack = NULL;
	*inst = NULL;
}

int	main(int ac, char **av)
{
	t_list	*astack;
	t_list	*bstack;
	t_list	*inst;

	if (ac < 2)
		return (0);
	init_stack(&astack, &bstack, &inst);
	input_stack(av, &astack);
	rate_rank(astack);
	check_all_sorted_node_cnt(astack);
	arrange_stack(&astack, &bstack, &inst);
	if (examine_sort(astack) == ac - 1)
		print_exit(inst);
	commence_sort(&astack, &bstack, &inst);
	check_all_sorted_node_cnt(astack);
	arrange_stack(&astack, &bstack, &inst);
	compression_inst(&inst);
	print_exit(inst);
	return (0);
}
