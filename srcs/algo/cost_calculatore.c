/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculatore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:16:07 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:44:49 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__next_value(t_stack *stack, int last_index)
{
	t_stack	*tmp; 

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index == last_index + 1)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int	__cost_calculatore(t_stack *stack, int to_find)
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
		return (1);
	else
		return (0);
}
