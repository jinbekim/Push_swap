NAME = push_swap

B_NAME = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra
B_FUNC = checker.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	input_instruction.c rate_rank.c

FUNC = push_swap.c \
	program_exit.c input_stack.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	input_instruction.c rate_rank.c \
	arrange_stack.c arrange_stack2.c \
	compression_inst.c commence_sort.c arrange_stack3.c

SRCS = $(addprefix ./srcs/, $(FUNC))
OBJS = $(addprefix ./objs/, $(FUNC:.c=.o))
B_SRCS = $(addprefix ./srcs/, $(B_FUNC))
B_OBJS = $(addprefix ./objs/, $(B_FUNC:.c=.o))

INC = -I./libft/includes/ -I.
FT = ./libft/libft.a
LIBFT = -L./libft -lft
DEBUG = -O3 -g3 -fsanitize=address

./objs/%.o : ./srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

all : $(FT) $(NAME)

$(FT) :
	$(MAKE) -C ./libft/

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

bonus : $(FT) $(B_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $(B_NAME)

clean :
	rm -f $(C_OBJS) $(P_OBJS)
	$(MAKE) clean -C ./libft/

fclean : clean
	rm -f $(NAME) $(B_NAME)
	$(MAKE) fclean -C ./libft/

re : fclean all

.PHONY : clean fclean re bonus all
