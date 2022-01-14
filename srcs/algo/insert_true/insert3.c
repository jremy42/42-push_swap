/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 16:46:31 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int __find_max_inf(t_stack *stack, int to_find)
{
	t_stack *tmp;
	int max_inf;
	
	tmp = stack;
	(void)to_find;
	max_inf = __find_max(stack);

	while (tmp != NULL)
	{
		if (tmp->sort != 3)
		{
			return (tmp->index);
		}
		tmp = tmp->next;
	}
	return (max_inf);
}

int __find_min_supp(t_stack *stack, int to_find)
{
	t_stack *tmp;
	int last_min_supp;
	int min_supp;
	
	min_supp = -1;
	tmp = stack;
	last_min_supp = __find_max(stack);

	while (tmp != NULL)
	{
		if (tmp->sort == 3)
		{
			if (tmp->index > to_find)
			{
				min_supp = tmp->index;
				if( min_supp < last_min_supp)
					last_min_supp = min_supp;
			}
	}
		tmp = tmp->next;
	}
	return (last_min_supp);
}

int __cost_calculator(t_stack *stack,int to_find)
{
	int r;
	int rr;
	t_stack *tmp;

	r = 0;
	rr = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index == to_find)
			break;
		r++;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		rr++;
		tmp = tmp->next;
	}
	if (r <= rr)
		return (r);
	else
		return (rr);
}

int __is_max(t_stack *stack, int to_find)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->sort == 3)
		{
			if (tmp->index > to_find)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int __cost_stack(t_data *data, t_index *index)
{
	t_stack *tmp;
	int n_index;
	int last_cost;
	int cost;
	
	tmp = data->b;
	n_index = tmp->index;
	if (__is_max(data->a,tmp->index) == 1)
	{
		last_cost = (__cost_calculator(data->a, __find_max_inf(data->a, tmp->index))
		+ __cost_calculator(tmp, tmp->index));
	}
	else
	{
		last_cost = (__cost_calculator(data->a, __find_min_supp(data->a, tmp->index))
		+ __cost_calculator(tmp, tmp->index));
	}
	while (tmp != NULL)
	{
		if (__is_max(data->a,tmp->index) == 1)
			cost = (__cost_calculator(data->a, __find_max_inf(data->a, tmp->index)) + __cost_calculator(data->b, tmp->index));
		else
			cost = (__cost_calculator(data->a, __find_min_supp(data->a, tmp->index)) + __cost_calculator(data->b, tmp->index));	
		if (cost <= last_cost && tmp->index < n_index)
		{
			n_index = tmp->index;
			last_cost = cost;
		}
		tmp = tmp->next;
	}
	index->index_b = n_index;
	if (__is_max(data->a,n_index) == 1)
		index->index_a = __find_max_inf(data->a, n_index);
	else
		index->index_a = __find_min_supp(data->a, n_index);
	return (1);
}


void	__first_push(t_data *data)
{
	data->b->sort = 3;
	__pa(data);
	data->b->sort = 3;
	__pa(data);
	if (data->a->nb > data->a->next->nb)
		__sa(data);
	return ;		
}


int	__insert_true(t_data *data, int next_index, int max_index)
{
	
	t_index index;
	t_stack *tmp;
	
	index.index_a = 0;
	index.index_b = 0;
	(void)next_index;
	(void)max_index;
	tmp = data->b;
	if (!data->b)
		return (next_index);
	__first_push(data);
	while (data->b != NULL)
	{
	__cost_stack(data, &index);
	__insert_sort_index(data, &index);
	}
	while (data->a->sort == 3 && data->a->index != 0)
		__ra(data);
	tmp = data->a;
	while (tmp->next != NULL)
	{
		if (tmp->sort == 3)
			tmp->sort = 2;
		tmp = tmp->next;
	}
	tmp->sort = 2;
	return (tmp->index + 1);
}
