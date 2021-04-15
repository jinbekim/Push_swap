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
void	add_instruct_ntimes(t_list **inst, char *instruct, int n);
void	input_stack(char **av, t_list **astack);

/*push_swap*/
void	rate_rank(t_list *astack);
void	check_all_sorted_node_cnt(t_list *astack);
int		check_how_many_sorted(t_list *start, t_list *node);
void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst);
void	btm_to_btm(t_list **stack, t_list **inst, t_list *chunk_head);
t_list	*find_chunk_btm(t_list *stack, t_list *chunk_head);
int		rev_rot_cnt(t_list *stack);
int		rot_cnt(t_list *stack, int rev_rot_cnt);
int		how_many_rot(t_list *stack, t_list *chunktail);
t_list	*select_chunk(t_list *astack);
void	commence_sort(t_list **astack, t_list **bstack, t_list **inst);
void	compression_inst(t_list **inst);

#endif
