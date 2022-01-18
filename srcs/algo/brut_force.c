/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 15:28:11 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__sort_bf(t_data *data)
{
	t_stack	*tmp;

	if (!data)
		return (0);	
	if (!data->a)
		return (0);
	tmp = data->a;
	if (data->b)
		return (0);
	if (tmp->index != 0)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->index + 1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	printf("data->max = %d\n",data->max);
	return (1);
}

void	__op_bf(t_data *copy, int op)
{
	if (op == RA)
		__ra(copy);
	if (op == RB)
		__rb(copy);
	if (op == RRA)
		__rra(copy);
	if (op == RRB)
		__rrb(copy);
	if (op == SA)
		__sa(copy);
	if (op == SB)
		__sb(copy);
	if (op == PB)
		__pb(copy);
	if (op == PA)
		__pa(copy);
	if (op == RRR)
		__rrr(copy);
	if (op == RR )
		__rr(copy);
	if (op == SS)
		__ss(copy);
}

int	__bf(t_data *data, int *op, int deep, int iterator)
{
	t_data	copy;
	int		i;

	if (__sort_bf(data) == 1)
		return (1);
	if (deep == iterator)
		return (0);
	i = 0;
	__copy_data(data, &copy);
	while (i < 8)
	{
		__op_bf(&copy, op[i]);
		if (__bf(&copy, op, deep + 1, iterator) == 1)
		{
			__free_data(data);
			__copy_data(&copy, data);
			__free_data(&copy);
			return (1);
		}
		__free_data(&copy);
		__copy_data(data, &copy);
		i ++;
	}
	return (0);
}

void	__print_bf(t_data *data, t_data *copy)
{
	__free_data(data);
	data = copy;
	__exit_ps(data, 0);
}

int	__under_6(t_data *data)
{
	t_data		copy;
	static int	op[8] = {RA, SA, RRA, PB, SB, RB, RRB, PA};
	int			i;
	int			iterator;

	i = 0;
	iterator = 1;
	__index(data);
	__copy_data(data, &copy);
	while (iterator < 10)
	{	
		if (__bf(&copy, op, 0, iterator) == 1)
		{
			__free_data(data);
			__copy_data(&copy, data);
			__print_bf(&copy, data);
		}
		else
		{
			__free_data(&copy);
			__copy_data(data, &copy);
		}
		iterator++;
	}
	return (0);
}
