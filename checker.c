#include "push_swap.h"

static void	error_exit(int *arr)
{
	write(2, "Error\n", 7);
	if (arr != NULL)
		free(arr);
	exit(0);
}
static int	*make_stack_a(int ac, char **av)
{
	int	*astack;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	astack = malloc(sizeof(int) * (ac - 1));
	if (astack == NULL)
		error_exit(NULL);
	while (av[++i])
	{
		j = -1;
		tmp = ft_atoi(av[i]);
		if (tmp == -1 && av[i][0] != '-')
			error_exit(astack);
		if (tmp == 0 && (av[i][0] != '0' || av[i][0] != '+'))
			error_exit(astack);
		while (++j < i)
		{
			if (astack[j] == tmp)
				error_exit(astack);
		}
		astack[i - 1] = tmp;
	}
	return (astack);
}


int	main(int ac, char **av)
{
	int	*astack;

	// 입력
	if (ac == 1)
		return (0);
	astack = make_stack_a(ac, av);

	if 올바른명령이면 저장 아니면 에러

	//실행

	//검사
	sorted a stack and empty b stack
	표준출력 ok\n or ko\n



}
