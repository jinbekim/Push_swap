#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*checker*/
void	error_exit(void);
void	print_exit(t_list *inst);
int		examine_sort(t_list *astack);
void	execute_inst(t_list **astack, t_list **bstack, t_list *inst);
void	execute_p(t_list **astack, t_list **bstack, char *inst);
void	execute_r(t_list **astack, t_list **bstack, char *inst);
void	execute_s(t_list **astack, t_list **bstack, char *inst);
void	input_instruction(t_list **inst);
void	input_stack(char **av, t_list **astack);

/*push_swap*/
void	rate_rank(t_list *astack);
void	check_longest_sorted_node(t_list *astack);
int		check_how_many_sorted(t_list *start, t_list *node);

#endif
