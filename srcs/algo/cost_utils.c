/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:19:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__cost_index_calculatore(t_stack *stack, int to_find)
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
		tmp = tmp->next;
		r++;
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

int	__cost_index(t_stack *stack, int next_index, int max_index)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	min = __cost_index_calculatore(stack, next_index);
	max = __cost_index_calculatore(stack, max_index);
	if (min < max)
		return (1);
	else
		return (0);
}