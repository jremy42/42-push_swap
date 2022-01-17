/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:18:03 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__stack_is_sort(t_data *data)
{
	t_stack	*tmp;
	int		index;

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

int	__repush_a(t_data *data, int next_index)
{
	if (__stack_is_sort(data) == 1)
		return (1);
	while (data->a->sort == 2)
		__ra(data);
	while (data->a->sort == 1)
	{
		if (data->a->index == next_index)
		{	
			__ra(data);
			next_index++;
		}
		__pb(data);
	}
	return (0);
}
