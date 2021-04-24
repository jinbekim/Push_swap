#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*checker*/
void	error_exit(void);
void	print_exit(t_list *inst);
int		examine_sort(t_list *astack);
int		examine_ascending(t_list *astack);
void	execute_inst(t_list **astack, t_list **bstack, t_list *inst);
void	execute_p(t_list **astack, t_list **bstack, char *inst);
void	execute_r(t_list **astack, t_list **bstack, char *inst);
void	execute_s(t_list **astack, t_list **bstack, char *inst);
void	input_instruction(t_list **inst);
void	add_instruct_ntimes(t_list **inst, char *instruct, int n);
void	input_stack(char **av, t_list **astack);

/*push_swap*/
void	rate_rank(t_list *astack);
void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst);
t_list	*select_chunk(t_list *astack);
void	compression_inst(t_list **inst);
void	add_and_execute_inst(\
t_list **astack, t_list **bstack, t_list **inst, char *instruct);
void	flush_bstack(\
t_list **astack, t_list **bstack, t_list **inst, int pivot);
int		find_hold1(t_list **stack, int pivot, int range);
int		find_hold2(t_list **stack, int pivot, int range);
void	rate_tmp_rank(t_list *astack);
int		check_how_many_sorted(t_list *start, t_list *node);
void	last_rotate(t_list **astack, t_list **bstack, t_list **inst);

#endif
