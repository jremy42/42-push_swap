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
		srcs/median.c

		
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = includes/push_swap.h
LIBFT = ./libft
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) ${HEADER} ${LIBFT}
		@make -C ${LIBFT}
		@cp libft/libft.a  ./libft.a
		$(CC) $(CFLAGS) ${OBJ} -Llibft -lft -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	#@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean