SRC = srcs/atol.c \
		srcs/parsing.c\
		srcs/push_swap.c\
		srcs/debug_list.c\
		srcs/stack_utils.c\
		srcs/swap.c\
		srcs/push.c\
		srcs/rotate.c\
		srcs/revrot.c\
		srcs/algo.c\
		srcs/algo_utils.c\
		srcs/index.c\
		srcs/quick_sort3.c\
		srcs/median.c\
		srcs/stack_sort_a.c\
		srcs/stack_sort_b.c

		
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
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