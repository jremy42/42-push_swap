/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 18:33:41 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__last_cost(t_data *data, t_stack *tmp)
{
	int	last_cost;
	int	max_inf;
	int	min_supp;

	max_inf = __find_max_inf(data->a, tmp->index);
	min_supp = __find_min_supp(data->a, tmp->index);
	if (__is_max(data->a, tmp->index) == 1)
	{
		last_cost = __cost_calculator(data->a,
				max_inf + __cost_calculator(tmp, tmp->index));
	}
	else
	{
		last_cost = __cost_calculator(data->a,
				min_supp + __cost_calculator(tmp, tmp->index));
	}
	return (last_cost);
}

int	__stack_calculator(t_data *data, t_stack *tmp, int lc, t_index *index)
{
	int		max_inf;
	int		min_supp;
	int		n_index;
	int		cost;

	n_index = tmp->index;
	while (tmp != NULL)
	{
		max_inf = __find_max_inf(data->a, tmp->index);
		min_supp = __find_min_supp(data->a, tmp->index);
		if (__is_max(data->a, tmp->index) == 1)
			cost = __cost_calculator(data->a, max_inf)
				+ __cost_calculator(data->b, tmp->index);
		else
			cost = __cost_calculator(data->a, min_supp)
				+ __cost_calculator(data->b, tmp->index);
		if (cost <= lc && tmp->index < n_index)
		{
			n_index = tmp->index;
			lc = cost;
		}
		tmp = tmp->next;
	}
	index->index_b = n_index;
	return (n_index);
}

int	__cost_stack(t_data *data, t_index *index)
{
	t_stack	*tmp;
	int		last_cost;
	int		n_index;

	tmp = data->b;
	last_cost = __last_cost(data, tmp);
	n_index = __stack_calculator(data, tmp, last_cost, index);
	if (__is_max(data->a, n_index) == 1)
		index->index_a = __find_max_inf(data->a, n_index);
	else
		index->index_a = __find_min_supp(data->a, n_index);
	return (1);
}

int	__return_index(t_stack *tmp)
{
	while (tmp->next != NULL)
	{
		if (tmp->sort == 3)
			tmp->sort = 2;
		tmp = tmp->next;
	}
	if (tmp->sort == 3)
		tmp->sort = 2;
	return (tmp->index);
}

int	__insert_true(t_data *data)
{
	t_index	index;
	t_stack	*tmp;

	index.index_a = 0;
	index.index_b = 0;
	tmp = data->b;
	if (!data->b)
		return (0);
	if (data->b->next)
		__first_push(data);
	while (data->b != NULL)
	{
		__cost_stack(data, &index);
		__insert_sort_index(data, &index);
	}
	while (data->a->sort == 3 && data->a->index != 0)
		__ra(data);
	tmp = data->a;
	return (__return_index(tmp));
}
