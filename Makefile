SRC = srcs/parsing/atol.c \
		srcs/parsing/parsing.c\
		srcs/push_swap.c\
		srcs/debug_list.c\
		srcs/stack_utils/stack_utils.c\
		srcs/operations/swap.c\
		srcs/operations/push.c\
		srcs/operations/rotate.c\
		srcs/operations/revrot.c\
		srcs/operations/list_op.c\
		srcs/algo/algo2.c\
		srcs/algo/algo.c\
		srcs/algo/algo_utils.c\
		srcs/algo/index.c\
		srcs/algo/quick_sort3.c\
		srcs/algo/median.c\
		srcs/algo/stack_sort_a.c\
		srcs/algo/stack_sort_b.c\
		srcs/algo/rotate_stack.c\
		srcs/algo/insert.c\
		srcs/algo/cost_calculatore.c\
		srcs/algo/algo2_utils.c\
		srcs/algo/next_pivot.c


		
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CC = gcc
OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))
HEADER = includes/push_swap.h
LIBFT = ./libft
OBJS_PATH = ./objs/
NAME = push_swap

# Create obj and dir
$(OBJS_PATH)%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) ${HEADER} ${LIBFT}
		@make -C ${LIBFT}
		@cp libft/libft.a  ./libft.a
		$(CC) $(CFLAGS) ${OBJ} -Llibft -lft -o $(NAME)

clean:
	rm -rf ${OBJS_PATH}
	#@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean