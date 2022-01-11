/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:42:55 by jremy             #+#    #+#             */
/*   Updated: 2022/01/11 17:48:43 by jremy            ###   ########.fr       */
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
	int				index;
	int				sort;
	int				nb;
	char			*cmd;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int size_a;
	int size_b;
	int pivot_a;
	int pivot_b;
	int	min;
	int	max;
	t_stack *median;
	t_stack	*a;
	t_stack	*b;
}	t_data;

// operation 
void	__sa(t_data *data);
void	__sb(t_data *data);
void	__ss_a(t_data *data);
void	__ss_b(t_data *data);
void	__ss(t_data *data);
void	__pb(t_data *data);
void	__pa(t_data *data);
void	__ra(t_data *data);
void	__rb(t_data *data);
void	__rr(t_data *data);
void	__rra(t_data *data);
void	__rrb(t_data *data);
void	__rrr(t_data *data);

// parsing 
int		__atol(const char *nb, t_data *data);
void	__parsing(char **input, t_data *data);
t_stack	*__stacknew(int *content);
int		is_present(int nb, t_stack *stack);

// utils
void	print_stack(t_stack *stack_a);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void stack_is_sort(t_data *data);
int __tmp_sort(t_data *data);
int __find_next_pivot(t_data *data);
void __size_stack_pivot(t_data *data);
void	__stack_add_front(t_stack **alst, t_stack *new);
void	__stackadd_back(t_stack **alst, t_stack *new);
void	__size_stack_ab(t_data *data);


//algo
int		__algo(t_data *data);
int		__find_pivot_ab(t_data *data);
int		__something_push_a(t_stack *stack, int pivot);
int		__something_push_b(t_stack *stack, int pivot);
int		__stack_is_sort_a(t_data *data);
int		__stack_is_sort_b(t_data *data);
int		__index(t_data *data);
void	__quick_sort_last_b(t_data *data);
void	__quick_sort_last_a(t_data *data);
void	print_pivot(t_stack *stack_a);
int		__size_stack(t_stack *stack);
void	__quick_sort_b(t_data *data);
void	__rotate_stack_a(t_data *data);
int		__next_pivot(t_stack *stack);
int		__pivot_size(t_stack *stack);



#endif 