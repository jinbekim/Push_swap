#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*checker*/
void	error_exit(void);
int		examine_sort(t_list *astack);
void	execute_inst(t_list **astack, t_list **bstack, t_list *inst);
void	execute_p(t_list **astack, t_list **bstack, char *inst);
void	execute_r(t_list **astack, t_list **bstack, char *inst);
void	execute_s(t_list **astack, t_list **bstack, char *inst);
void	make_inst_list(t_list **inst);
void	make_stack_list(char **av, t_list **astack);

/*push_swap*/
#endif
