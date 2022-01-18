/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:46 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 17:21:34 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__create_next_chunks(t_data *data)
{
	int	len;
	int	size;

	size = __pivot_size(data->b);
	__find_pivot_ab(data);
	len = 0;
	while (len < size && __something_push_b(data->b, data->pivot_b))
	{
		if (data->b->nb > data->pivot_b)
		{
			data->b->sort = 1;
			__pa(data);
		}
		else
			__rb(data);
		len++;
	}
}

int	__something_is_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->sort == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	__chunks1(t_data *data, int next_index, int rotate)
{
	while (data->a->sort != 2)
	{
		if (data->a->index == next_index && rotate == 0)
		{
			data->a->sort = 2;
			__ra(data);
			next_index++;
		}
		else
			__pb(data);
		if (data->a->sort == 2)
			break ;
	}
	return (next_index);
}

void	__create_chunks(t_data *data, int pivot, int sc, int next_index)
{
	int	len;
	int	size;
	int	rotate;

	size = __pivot_size(data->a);
	__size_stack_ab(data);
	rotate = 0;
	len = 0;
	if (size <= sc)
		next_index = __chunks1(data, next_index, rotate);
	while (len < size && __something_push_a(data->a, pivot))
	{
		if (data->a->sort == 2)
			break ;
		if (data->a->index == next_index && rotate == 0)
			next_index = __rotate_index(data, next_index);
		if (data->a->nb <= pivot)
			__pb(data);
		else
			rotate = __rotate_a(data, rotate);
		len++;
	}
	if (rotate > 0 && __something_is_sort(data->a) == 1)
		__rotate_chunks(data, rotate);
	__create_next_chunks(data);
}
