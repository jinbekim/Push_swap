NAME = checker
NAME2 = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
FUNC = checker.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	input_instruction.c rate_rank.c
FUNC2 = push_swap.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	input_instruction.c \
	rate_rank.c arrange_stack.c arrange_stack2.c \
	compression_inst.c commence_sort.c arrange_stack3.c

C_SRCS = $(addprefix ./srcs/, $(FUNC))
C_OBJS = $(addprefix ./objs/, $(FUNC:.c=.o))
P_SRCS = $(addprefix ./srcs/, $(FUNC2))
P_OBJS = $(addprefix ./objs/, $(FUNC2:.c=.o))
INC = -I./libft/includes/ -I.
LIBFT = -L./libft -lft
DEBUG = -O3 -g3 -fsanitize=address

./objs/%.o : ./srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

all : $(NAME) $(NAME2)

$(NAME) : $(C_OBJS)
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

$(NAME2) : $(P_OBJS)
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

clean :
	rm -f $(C_OBJS) $(P_OBJS)
	$(MAKE) clean -C ./libft/

fclean : clean
	rm -f $(NAME) $(NAME2)
	$(MAKE) fclean -C ./libft/

re : fclean all

.PHONY : clean fclean re
