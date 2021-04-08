NAME = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = checker.c error_exit.c examine_sort.c \
	execute_inst.c execute_p.c execute_r.c execute_s.c\
	make_inst_list.c make_stack_list.c
OBJS = $(SRCS:.c=.o)
INC = -I./libft/includes/

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $?

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : clean all

.PHONY : clean fclean re
