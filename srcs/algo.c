/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/07 19:28:44 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_quick_sort_a(t_data *data)
{
	t_stack *pivot;
	int len;

	ft_find_pivot_ab(data);
	ft_size_stack_ab(data);
	len = 0;
	if (data->size_a < 4 || data->a->sort == 1)
	{
		print_pivot(data->median);
		ft_quick_sort_last_a(data);
		return;
	}

	while (len < data->size_a && ft_something_push_a(data->a,data->pivot_a) && data->a->sort != 1)
	{
		if (data->a->nb < data->pivot_a)
			ft_pb(data);
		else
			ft_ra(data);
		len++;
	}
	pivot = ft_stacknew(&data->pivot_a);
	ft_stack_add_front(&data->median, pivot);
	ft_quick_sort_a(data);
}

int ft_algo(t_data *data)
{
	print_list(data->a,data->b);
	ft_index(data);
	stack_is_sort(data);
	ft_quick_sort_a(data);
	stack_is_sort(data);
	print_list(data->a,data->b);
	return (0);
}