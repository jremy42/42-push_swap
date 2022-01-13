/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/13 19:07:11 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int __stack_is_sort(t_data *data)
{
	t_stack *tmp;
	int index;

	index = 0;
	tmp = data->a;
	if (data->a->index != 0)
		return (0);
	while (tmp != NULL)
	{
		if (tmp->index != index)
			return (0);
		index++;
		tmp = tmp->next;
	}
	return (1);
}
int __repush_a(t_data *data, int next_index)
{
	if (__stack_is_sort(data) == 1)
		return (1);
	while(data->a->sort == 2)
			__ra(data);
	while(data->a->sort == 1)
	{
		if(data->a->index == next_index)
		{	
			__ra(data);
			next_index++;
		}
		__pb(data);
	}
	return (0);
}

int __insert_min(t_data *data, int next_index)
{
		int rotate;

		rotate = __cost_calculatore(data->b, next_index);
		
	if (rotate == 1)
	{
		while (data->b->index != next_index)
			__rb(data);
		data->b->sort = 2;
		__pa(data);
		__ra(data);
	}
	else 
	{
		while (data->b->index != next_index)
			__rrb(data);
		data->b->sort = 2;
		__pa(data);
		__ra(data);
	}

		return (1);
}

int __insert_max(t_data *data, int max_index)
{
		int rotate;

		rotate = __cost_calculatore(data->b, max_index);
		
	if (rotate == 1)
	{
		while (data->b->index != max_index)
			__rb(data);
		data->b->sort = 2;
		__pa(data);
	}
	else 
	{
		while (data->b->index != max_index)
			__rrb(data);
		data->b->sort = 2;
		__pa(data);
	}

		return (1);
}

void	__first_push(t_data *data, int next_index)
{
	__pa(data);
	__pa(data);
	if (data->a->nb > data->a->next->nb)
		__sa(data);
	return ;		
}
int	__insert_true(t_data *data, int next_index, int max_index)
{
	int min;
	int max;
	int a;
	int b;

	__first_push(data, next_index);
	while (data->b != NULL)
	{
		a = __cost_stack_a(data);
		b = __cost_stack_b(data)
		
	}
	if (!data->b)
		return (next_index);
	min = 0;
	max = 0;

	if (__cost_index(data->b, next_index, max_index) == 1)
		min = __insert_min(data, next_index);
	else
		max = __insert_max(data, max_index);	
	return (__insert(data, next_index + min, max_index - max));
}
