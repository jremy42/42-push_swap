/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 12:54:08 by jremy            ###   ########.fr       */
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
	//printf("min supp = %d\n",last_min_supp);
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
	//printf("min supp = %d\n",last_min_supp);
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

int __cost_stack(t_data *data)
{
	t_stack *tmp;
	int index;
	int last_cost;
	int cost;
	
	tmp = data->b;
	index = tmp->index;
	if (__is_max(data->a,tmp->index) == 1)
	{
		last_cost = (__cost_calculator(data->a, __find_max_inf(data->a, tmp->index))
		+ __cost_calculator(tmp, tmp->index)) + 1;
	}
	else
	{
		last_cost = (__cost_calculator(data->a, __find_min_supp(data->a, tmp->index))
		+ __cost_calculator(tmp, tmp->index));
	}
	printf("last cost = %d\n", last_cost);	
	while (tmp != NULL)
	{
		if (__is_max(data->a,tmp->index) == 1)
			cost = (__cost_calculator(data->a, __find_max_inf(data->a, tmp->index)) + __cost_calculator(data->b, tmp->index)) + 1;
		else
			cost = (__cost_calculator(data->a, __find_min_supp(data->a, tmp->index)) + __cost_calculator(data->b, tmp->index));	
		printf("index = %d | cost = %d\n\n", tmp->index, cost);
		if (cost <= last_cost && tmp->index < index)
		{
			index = tmp->index;
			last_cost = cost;
		}
		tmp = tmp->next;
	}
	return (index);
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
	
	int index;
	t_stack *tmp;

	(void)next_index;
	(void)max_index;
	tmp = data->b;
	__first_push(data);
	index  = __cost_stack(data);
			
	if (!data->b)
		return (next_index);
	printf("index le moins cher = %d \n", index);
	print_list(data->a, data->b);
	exit(0);
	/*

	if (__cost_index(data->b, next_index, max_index) == 1)
		min = __insert_min(data, next_index);
	else
		max = __insert_max(data, max_index);	
	return (__insert(data, next_index + min, max_index - max));
	*/
}
