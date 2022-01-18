/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:42:55 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 18:57:06 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
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
	struct s_stack	*next;
}	t_stack;

typedef struct s_cmd
{
	int				cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	int		size_a;
	int		size_b;
	int		size_final;
	int		pivot_a;
	int		pivot_b;
	int		min;
	int		max;
	t_cmd	*cmd;
	t_stack	*a;
	t_stack	*b;
}	t_data;

typedef struct s_index
{
	int	index_a;
	int	index_b;
}	t_index;

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
int		__insert_cmd(t_data *data, int op);
void	__cmdadd_back(t_cmd **alst, t_cmd *new);
t_cmd	*__cmdnew(int cmd);

// parsing 
int		__atol(const char *nb, t_data *data);
void	__parsing(char **input, t_data *data);
t_stack	*__stacknew(int *content);
int		is_present(int nb, t_stack *stack);
// algo insert 
void	__insert_sort_index(t_data *data, t_index *index);
int		__is_max(t_stack *stack, int to_find);
int		__cost_calculator(t_stack *stack, int to_find);
int		__find_min_supp(t_stack *stack, int to_find);
int		__find_max_inf(t_stack *stack, int to_find);
void	__first_push(t_data *data);
int		__insert_true(t_data *data);
int		__stack_calculator(t_data *data, t_stack *tmp, int lc, t_index *index);

//algo utils
int		__something_push_a(t_stack *stack, int pivot);
int		__something_push_b(t_stack *stack, int pivot);
int		__size_stack(t_stack *stack);
int		__find_min(t_stack *stack);
int		__find_max(t_stack *stack);

//algo
int		__algo4(t_data *data);

// bf utils
t_stack	*__copy_stack(t_stack *stack);
t_cmd	*__copy_cmd(t_cmd *cmd);
t_data	*__copy_data(t_data *data, t_data *new);
void	__free_cmd(t_data *data);
void	__free_data(t_data *data);

//bf
int		__under_6(t_data *data);
int		__sort_bf(t_data *data);

//chunks utils
int		__rotate_a(t_data *data, int rotate);
int		__rotate_index(t_data *data, int next_index);
void	__rotate_chunks(t_data *data, int rotate);
int		__size_chunks(t_data *data);
int		__find_pivot_chunks(t_data *data, int chunks);
//chunks
void	__create_chunks(t_data *data, int pivot, int sc, int next_index);
//cost_utils
int		__cost_index(t_stack *stack, int next_index, int max_index);
int		__cost_index_calculatore(t_stack *stack, int to_find);

// index
void	__insert_index(t_data *data, int *tab);
int		__index(t_data *data);

//median utils
int		__pivot_size(t_stack *stack);
int		__find_pivot_ab(t_data *data);

//stack utils
void	__stack_add_front(t_stack **alst, t_stack *new);
void	__size_stack_ab(t_data *data);
void	__size_stack_pivot(t_data *data);
int		__tmp_sort(t_data *data);
void	__stackadd_back(t_stack **alst, t_stack *new);
t_stack	*__stacknew(int *content);
int		is_present(int nb, t_stack *stack);
t_cmd	*__cmdnew(int cmd);
void	__cmdadd_back(t_cmd **alst, t_cmd *new);
int		__insert_cmd(t_data *data, int op);

void	__exit_ps(t_data *data, int error);
void	__free_stack(t_stack *stack);
void	__error(char *error, t_data *data);
void	print_cmd_lst(t_cmd *cmd);

/*
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
void	__exit_ps(t_data *data, int error);
void	__free_stack(t_stack *stack);
void	__free_cmd(t_data *data);
void	__free_stack(t_stack *stack);
void	__error(char *error, t_data *data);
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
int		__insert_true(t_data *data);
void	__insert_sort_index(t_data *data, t_index *index);
//brut force
void	__free_data(t_data *data);
t_data	*__copy_data(t_data *data, t_data *new);
t_cmd 	*__copy_cmd(t_cmd *cmd);
t_stack *__copy_stack(t_stack *stack);
int __under_6(t_data *data);
void __op_bf(t_data *copy, int op);
int	__sort_bf(t_data *data);
// chunks utils
int		__rotate_a(t_data *data, int rotate);
int		__rotate_index(t_data *data, int next_index);
void	__rotate_chunks(t_data *data, int rotate);
// insert utils
void	__first_push(t_data *data);
int	__find_max_inf(t_stack *stack, int to_find);
int	__find_min_supp(t_stack *stack, int to_find);
int	__cost_calculator(t_stack *stack, int to_find);
int	__is_max(t_stack *stack, int to_find);
*/
#endif