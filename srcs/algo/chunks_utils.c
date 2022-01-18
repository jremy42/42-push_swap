/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 17:17:32 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__find_pivot_chunks(t_data *data, int chunks)
{
	t_stack	*tmp;

	tmp = data->a;
	while (tmp != NULL)
	{
		if (tmp->index == chunks)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int	__size_chunks(t_data *data)
{
	t_stack	*tmp;
	int		size;
	int		i;

	tmp = data->a;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	data->size_final = i;
	size = i / NB_CHUNKS;
	return (size);
}

void	__rotate_chunks(t_data *data, int rotate)
{
	while (rotate > 0)
	{
		__rra(data);
		rotate--;
	}
}

int	__rotate_index(t_data *data, int next_index)
{
	data->a->sort = 2;
	__ra(data);
	next_index++;
	return (next_index);
}

int	__rotate_a(t_data *data, int rotate)
{
	__ra(data);
	rotate++;
	return (rotate);
}
