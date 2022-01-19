/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 18:33:07 by jremy            ###   ########.fr       */
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

int	__under_50(t_data *data)
{
	int	size;

	size = data->size_a;
	if (data->size_a < 6)
	{
		__under_6(data);
		return (1);
	}
	if (__sort_bf(data) == 1)
		return (1);
	while (size > 0)
	{
		if (data->a->index == 0)
			__ra(data);
		__pb(data);
		size--;
	}
	__insert_true(data);
	print_cmd_lst(data->cmd);
	__exit_ps(data, 0);
	return (1);
}

void	__insert_algo(t_data *data, int chunks, int next_index, int pivot)
{
	while (__sort_bf(data) != 1)
	{
		pivot = __find_pivot_chunks(data, chunks);
		__create_chunks(data, pivot, __size_chunks(data), next_index + 1);
		next_index = __insert_true(data);
		__replace_for_second_insert(data, next_index);
		next_index = __insert_true(data);
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
}

int	__algo4(t_data *data)
{
	int	chunks;
	int	pivot;
	int	next_index;

	__index(data);
	chunks = 0;
	pivot = 0;
	if (data->size_a < 50)
		__under_50(data);
	else
		chunks = __size_chunks(data);
	next_index = -1;
	__insert_algo(data, chunks, next_index, pivot);
	print_cmd_lst(data->cmd);
	__exit_ps(data, 0);
	return (0);
}
