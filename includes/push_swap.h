/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:42:55 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 12:50:20 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		min;
	int		max;
	int		index;
	int		nb;
	char	*cmd;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

int		ft_atol(const char *nb, t_data *data);
void	ft_parsing(char **input, t_data *data);
t_stack	*ft_stacknew(int *content);
void	print_list(t_stack *stack);
void	ft_stackadd_back(t_stack **alst, t_stack *new);
int		is_present(int nb, t_stack *stack);
t_stack	*ft_swap_a(t_stack *data);

#endif 