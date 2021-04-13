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
	check_longest_sorted_node(astack);
	// 회전 및 b스택 넘김, 청크값이 모두 같으면 회전시켜서 정렬, 혹은 그대로 반환
	arrange_stack(&astack, &bstack, &inst, ac);
	//commence_sort(&astack, &bstack, &inst); //회전시켜서 푸시 검사 회전시켜서 푸시 검사 .... 반복 각 노드마다 명령어 수를 구한뒤 제일적은것 실행?
	print_exit(inst);
	return (0);
}
