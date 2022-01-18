/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 12:53:02 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__replace_for_second_insert(t_data *data, int next_index)
{	
	while (data->a->sort == 2)
	{
		next_index = data->a->index;
		__ra(data);
	}
	next_index++;
	while (data->a->sort == 1)
	{
		if (data->a->index == next_index)
		{
			data->a->sort = 2;
			__ra(data);
			next_index++;
		}
		else
			__pb(data);
	}
	return (next_index);
}

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

void	__create_chunks(t_data *data, int pivot, int size_chunks, int next_index)
{
	int	len;
	int	size;
	int	rotate;

	size = __pivot_size(data->a);
	__size_stack_ab(data);
	rotate = 0;
	len = 0;
	if (size <= size_chunks)
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
	}
	while (len < size && __something_push_a(data->a, pivot))
	{
		if (data->a->sort == 2)
			break ;
		if (data->a->index == next_index && rotate == 0)
		{
			data->a->sort = 2;
			__ra(data);
			next_index++;
		}
		if (data->a->nb <= pivot)
			__pb(data);
		else
		{
			__ra(data);
			rotate++;
		}
		len++;
	}
	if (rotate > 0 && __something_is_sort(data->a) == 1)
	{
		while (rotate > 0)
		{
			__rra(data);
			rotate--;
		}
	}
	__create_next_chunks(data);
}

int	__under_50(t_data *data)
{
	if (data->size_a < 6)
	{
		__under_6(data);
		return (1);
	}
	while (data->a != NULL)
		__pb(data);
	//print_list(data->a, data->b);
	__insert_true(data, __find_min(data->b), __find_max(data->b));
	//print_list(data->a, data->b);
	return (1);
}

int	__algo4(t_data *data)
{
	int	chunks;
	int	pivot;
	int	min;
	int	next_index;

	__index(data);
	if (data->size_a < 50)
	{
		__under_50(data);
		__exit_ps(data, 0);
		return (0);
	}
	else
		chunks = __size_chunks(data);
	min = __find_min(data->a);
	next_index = -1;
	while (__sort_bf(data) != 1)
	{
		pivot = __find_pivot_chunks(data, chunks);
		__create_chunks(data, pivot, __size_chunks(data), next_index + 1);
		next_index = __insert_true(data, __find_min(data->b), __find_max(data->b));
		__replace_for_second_insert(data, next_index);	
		next_index = __insert_true(data, __find_min(data->b),__find_max(data->b));
		while (data->a->sort == 2)
		{
			next_index = data->a->index;
			if (data->a->index == 0)
				break ;
			__ra(data);
		}
		if (data->a->next->index == 0)
		{
			__ra(data);
			break ;
		}
		if (data->a->index == 0)
			break ;
		chunks += chunks;
	}
	//print_list(data->a, data->b);
	__exit_ps(data, 0);
	return (0);
}