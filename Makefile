#CONFIG

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES

HEADER = ./includes/push_swap.h

SRCS = ./checker_main.c ./sort_operations_second.c  ./swap2.c \
			 ./swap5.c ./exit_functions.c ./init_b.c  ./min_max.c ./sort_pile.c \
			 ./swap3.c ./utils.c ./get_node_info.c ./main.c ./sort_operations.c \
			 ./swap1.c ./swap4.c

OBJS = $(SRCS:.c=.o)

#COMMANDS

all : $(NAME)

%.o: %.c $(HEADER)
	${CC} ${FLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"


clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted.$(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)all files deleted.$(DEFAULT)"

re : fclean all

.PHONY:
	all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
