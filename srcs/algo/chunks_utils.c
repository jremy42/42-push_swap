/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:14:06 by jremy            ###   ########.fr       */
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
