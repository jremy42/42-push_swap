/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:32:01 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 18:34:19 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	__rotate_calculator(t_stack *stack, int to_find)
{
	int		r;
	int		rr;
	t_stack	*tmp;

	r = 0;
	rr = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index == to_find)
			break ;
		r++;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		rr++;
		tmp = tmp->next;
	}
	if (r == 0)
		return (-1);
	if (r <= rr)
		return (0);
	else
		return (1);
}

void	__rr_rotate(t_data *data, t_index *index)
{
	while (data->a->index != index->index_a
		|| data->b->index != index->index_b)
	{
		__rra(data);
		__rrb(data);
		if (data->a->index == index->index_a)
		{
			while (data->b->index != index->index_b)
				__rrb(data);
			return ;
		}
		if (data->b->index == index->index_b)
		{
			while (data->a->index != index->index_a)
				__rra(data);
			return ;
		}
	}
}

void	__r_rotate(t_data *data, t_index *index)
{
	while (data->a->index != index->index_a
		|| data->b->index != index->index_b)
	{
		__ra(data);
		__rb(data);
		if (data->a->index == index->index_a)
		{
			while (data->b->index != index->index_b)
				__rb(data);
			return ;
		}
		if (data->b->index == index->index_b)
		{
			while (data->a->index != index->index_a)
				__ra(data);
			return ;
		}
	}
}

void	__same_rotate(t_data *data, t_index *index)
{
	if (__rotate_calculator(data->a, index->index_a) == 1)
	{
		__rr_rotate(data, index);
		return ;
	}
	else
	{
		__r_rotate(data, index);
		return ;
	}
}

void	__insert_sort_index(t_data *data, t_index *index)
{
	if (__rotate_calculator(data->a, index->index_a)
		== __rotate_calculator(data->b, index->index_b))
		__same_rotate(data, index);
	else
	{
		if (__rotate_calculator(data->a, index->index_a) == 1)
			while (data->a->index != index->index_a)
				__rra(data);
		else
			while (data->a->index != index->index_a)
				__ra(data);
		if (__rotate_calculator(data->b, index->index_b) == 1)
			while (data->b->index != index->index_b)
				__rrb(data);
		else
			while (data->b->index != index->index_b)
				__rb(data);
	}
	__pa(data);
	data->a->sort = 3;
	return ;
}
