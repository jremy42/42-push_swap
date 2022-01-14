/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 10:32:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__find_min(t_stack *stack)
{
	t_stack *tmp;
	int		min;
	
	
	tmp = stack;
	min = tmp->index;
	printf("find min\n");
	while (tmp != NULL && tmp->sort != 2)
	{
		if(tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	printf("min = %d\n", min);
	return (min);
}

int	__find_max(t_stack *stack)
{
	t_stack *tmp;
	int		max;
	
	
	tmp = stack;
	max = tmp->index;
	while (tmp != NULL && tmp->sort != 2)
	{
		if(tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int __cost_index_calculatore(t_stack *stack, int to_find)
{
	int r;
	int rr;
	t_stack *tmp;

	r = 0;
	rr = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index == to_find)
			break;
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
	int min;
	int max;

	min = 0;
	max = 0;
	
	min = __cost_index_calculatore(stack, next_index);
	max = __cost_index_calculatore(stack, max_index);
	if(min < max)
		return (1);
	else
		return (0);
}