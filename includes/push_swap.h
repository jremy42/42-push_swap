/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:42:55 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 19:39:09 by jremy            ###   ########.fr       */
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
	int				min;
	int				max;
	int				index;
	int				nb;
	char			*cmd;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int size_a;
	int size_b;
	int median_a;
	int median_b;
	t_stack	*a;
	t_stack	*b;
}	t_data;

// operation 
void	ft_swap_a(t_data *data);
void	ft_swap_b(t_data *data);
void	ft_swap_ab_a(t_data *data);
void	ft_swap_ab_b(t_data *data);
void	ft_swap_ab(t_data *data);
void	ft_stack_add_front(t_stack **alst, t_stack *new);
void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);
void	ft_rotate_a(t_data *data);
void	ft_rotate_b(t_data *data);
void	ft_rotate_ab(t_data *data);
void	ft_stackadd_back(t_stack **alst, t_stack *new);
void	ft_size_stack(t_data *data);
void	ft_revrotate_a(t_data *data);
void	ft_revrotate_b(t_data *data);
void	ft_revrotate_ab(t_data *data);
// parsing 
int		ft_atol(const char *nb, t_data *data);
void	ft_parsing(char **input, t_data *data);
t_stack	*ft_stacknew(int *content);
int		is_present(int nb, t_stack *stack);

// utils
void	print_stack(t_stack *stack_a);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void stack_is_sort(t_data *data);
int ft_tmp_sort(t_data *data);

//algo

int ft_algo(t_data *data);
int ft_find_median_ab(t_data *data);
int ft_something_push(t_data *data);


#endif 