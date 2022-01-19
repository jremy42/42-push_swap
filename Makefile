SRC = srcs/parsing/atol.c \
		srcs/parsing/parsing.c\
		srcs/push_swap.c\
		srcs/debug_list.c\
		srcs/stack_utils/stack_utils.c\
		srcs/stack_utils/stack_utils2.c\
		srcs/operations/swap.c\
		srcs/operations/push.c\
		srcs/operations/rotate.c\
		srcs/operations/revrot.c\
		srcs/operations/list_op.c\
		srcs/algo/insert/insert.c\
		srcs/algo/insert/insert_utils.c\
		srcs/algo/insert/insert_index.c\
		srcs/algo/algo_utils.c\
		srcs/algo/algo.c\
		srcs/algo/brut_force_utils.c\
		srcs/algo/brut_force.c\
		srcs/algo/chunks_utils.c\
		srcs/algo/chunks.c\
		srcs/algo/cost_calculatore.c\
		srcs/algo/cost_utils.c\
		srcs/algo/index.c\
		srcs/algo/median.c\
		srcs/algo/median_utils.c\
		srcs/exit.c

SRC_CHECKER =srcs/parsing/atol.c \
		srcs/parsing/parsing.c\
		srcs/debug_list.c\
		srcs/stack_utils/stack_utils.c\
		srcs/stack_utils/stack_utils2.c\
		srcs/operations/swap.c\
		srcs/operations/push.c\
		srcs/operations/rotate.c\
		srcs/operations/revrot.c\
		srcs/operations/list_op.c\
		srcs/algo/insert/insert.c\
		srcs/algo/insert/insert_utils.c\
		srcs/algo/insert/insert_index.c\
		srcs/algo/algo_utils.c\
		srcs/algo/algo.c\
		srcs/algo/brut_force_utils.c\
		srcs/algo/brut_force.c\
		srcs/algo/chunks_utils.c\
		srcs/algo/chunks.c\
		srcs/algo/cost_calculatore.c\
		srcs/algo/cost_utils.c\
		srcs/algo/index.c\
		srcs/algo/median.c\
		srcs/algo/median_utils.c\
		srcs/exit.c\
		srcs/checker/checker.c

IFLAGS = -I includes/ -I libft/includes
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))
OBJ_CHECKER = $(addprefix $(OBJS_PATH_CHECKER), $(SRC_CHECKER:.c=.o))

HEADER = includes/push_swap.h
LIBFT = ./libft
OBJS_PATH = ./objs/
OBJS_PATH_CHECKER = ./objs/checker/

NAME = push_swap

# Create obj and dir
$(OBJS_PATH)%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_PATH_CHECKER)%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

checker: $(OBJ_CHECKER) ${HEADER} ${LIBFT}
		@make -C ${LIBFT}
		#@cp libft/libft.a  ./libft.a
		$(CC) $(CFLAGS) $(OBJ_CHECKER) -Llibft -lft -o checker

$(NAME): $(OBJ) ${HEADER} ${LIBFT}
		@make -C ${LIBFT}
		#@cp libft/libft.a  ./libft.a
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