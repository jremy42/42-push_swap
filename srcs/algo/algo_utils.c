/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:04:50 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 15:47:49 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__something_push_a(t_stack *stack, int pivot)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->nb <= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int	__something_push_b(t_stack *stack, int pivot)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->nb >= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int	__size_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		a;

	a = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		a++;
	}
	return (a);
}

int	__find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	if (!stack)
		return (0);
	tmp = stack;
	min = tmp->index;
	while (tmp != NULL && tmp->sort != 2)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	__find_max(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	if (!stack)
		return (0);
	tmp = stack;
	max = tmp->index;
	while (tmp != NULL && tmp->sort != 2)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}