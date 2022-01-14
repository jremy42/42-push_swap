/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:42:55 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 11:00:59 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# define PA 0
# define PB 1
# define RRA 2
# define RRB 3
# define RA 4
# define RB 5
# define SA 6
# define SB 7
# define RRR 8
# define RR 9
# define SS 10
# define NB_CHUNKS 2

typedef struct s_stack
{
	int				index;
	int				sort;
	int				nb;
	int				cost;
	char			*cmd;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cmd
{
	int				cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	int size_a;
	int size_b;
	int size_final;
	int pivot_a;
	int pivot_b;
	int	min;
	int	max;
	t_stack *median;
	t_cmd *cmd;
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
void __insert_cmd(t_data *data,int op);
void	__cmdadd_back(t_cmd **alst, t_cmd *new);
t_cmd	*__cmdnew(int cmd);

// parsing 
int		__atol(const char *nb, t_data *data);
void	__parsing(char **input, t_data *data);
t_stack	*__stacknew(int *content);
int		is_present(int nb, t_stack *stack);

// utils
void	print_stack(t_stack *stack_a);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void	stack_is_sort(t_data *data);
int		__tmp_sort(t_data *data);
int		__find_next_pivot(t_data *data);
void	__size_stack_pivot(t_data *data);
void	__stack_add_front(t_stack **alst, t_stack *new);
void	__stackadd_back(t_stack **alst, t_stack *new);
void	__size_stack_ab(t_data *data);
void	print_cmd(int cmd);
void	print_cmd_lst(t_cmd *cmd);


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

//algo2
int		__algo2(t_data *data);
int		__first_insert(t_data *data, int last_index, int max_index);
int		__cost_calculatore(t_stack *stack,int to_find);
int		__next_value(t_stack *stack, int last_index);
int 	__repush_a(t_data *data, int next_index);
int		__find_max(t_stack *stack);
int		__find_min(t_stack *stack);
int		__cost_index(t_stack *stack, int next_index, int max_index);

//algo3
int		__algo3(t_data *data);
void	__create_chunks(t_data *data, int pivot, int chunks, int next_index);
void	__create_next_chunks(t_data *data);
int		__size_chunks(t_data *data);
int		__find_pivot_chunks(t_data *data, int chunks);
int		__insert(t_data *data, int last_index, int max_index);

//algo4
int		__algo4(t_data *data);
int	__insert_true(t_data *data, int next_index, int max_index);



#endif 