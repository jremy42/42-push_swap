/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:34 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 17:47:10 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__first_push(t_data *data)
{
	data->b->sort = 3;
	__pa(data);
	data->b->sort = 3;
	__pa(data);
	if (data->a->nb > data->a->next->nb)
		__sa(data);
	return ;
}

int	__find_max_inf(t_stack *stack, int to_find)
{
	t_stack	*tmp;

	tmp = stack;
	(void)to_find;
	while (tmp != NULL)
	{
		if (tmp->sort != 3)
		{
			return (tmp->index);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	__find_min_supp(t_stack *stack, int to_find)
{
	t_stack	*tmp;
	int		last_min_supp;
	int		min_supp;

	min_supp = -1;
	tmp = stack;
	last_min_supp = __find_max(stack);
	while (tmp != NULL)
	{
		if (tmp->sort == 3)
		{
			if (tmp->index > to_find)
			{
				min_supp = tmp->index;
				if (min_supp < last_min_supp)
					last_min_supp = min_supp;
			}
		}
		tmp = tmp->next;
	}
	return (last_min_supp);
}

int	__cost_calculator(t_stack *stack, int to_find)
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
	if (r <= rr)
		return (r);
	else
		return (rr);
}

int	__is_max(t_stack *stack, int to_find)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->sort == 3)
		{
			if (tmp->index > to_find)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
