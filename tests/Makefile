# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngiroux <ngiroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 10:12:53 by ngiroux           #+#    #+#              #
#    Updated: 2022/01/09 15:59:13 by ngiroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define
DEF			= FT_TESTED='"1"'\
			FT00_TEST='"1111"' 
DEFS		= $(addprefix -D, $(DEF))

# Names 
NAME		= tester
LIB_NAME	= libunit.a
FILES		= 00_parsing/00_launcher.c 00_parsing/01_int_min.c 00_parsing/02_int_max.c\
			00_parsing/03_doublons.c\
			00_parsing/04_sort1.c\
			00_parsing/05_sort2.c\
			00_parsing/06_sort3.c\
			00_parsing/07_char.c\
			00_parsing/08_empty.c\
			00_parsing/09_empty2.c\
			00_parsing/10_empty3.c\
			01_parsing_checker/00_launcher2.c\
			01_parsing_checker/01_int_min_c.c\
			01_parsing_checker/02_int_max_c.c\
			01_parsing_checker/03_doublons_c.c\
			01_parsing_checker/04_input1_c.c\
			01_parsing_checker/05_input2_c.c\
			01_parsing_checker/06_input3_c.c\
			01_parsing_checker/07_input4_c.c\
			01_parsing_checker/08_char_c.c\
			01_parsing_checker/08_empty_c.c\
			01_parsing_checker/09_empty2_c.c\
			01_parsing_checker/10_empty3_c.c\
			main.c

# Paths
LIB_PATH		=framework/
INCS_PATH		=./incs/
LIB_INCS_PATH	=$(LIB_PATH)$(INCS_PATH)
OBJS_PATH		=./objs/

# Objects
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))

# Flags + compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= $(DEFS)
LIB_CC	= -L$(LIB_PATH) -lunit
INCS	= -I $(LIB_INCS_PATH) -I $(INCS_PATH) -I $(INCS_PATH)

# Create obj and dir
$(OBJS_PATH)%.o: %.c
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@  

# Compiling command
all:		${NAME}

${NAME}:	${OBJS}
			make -C $(LIB_PATH)
			cp ../push_swap push_swap
			cp ../checker checker
			$(CC) $(CFLAGS) $(OBJS) $(LIB_CC) -o $(NAME)

test:		${NAME}
			./${NAME} || true
# Other rules
clean:
			rm -rf ${OBJS_PATH}
			rm -rf push_swap
			make -C $(LIB_PATH) clean

fclean:		clean
			rm -rf ${NAME}
			rm -rf ${LIB_NAME}
			make -C $(LIB_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re test
