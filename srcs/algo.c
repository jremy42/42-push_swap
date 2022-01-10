/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 13:15:30 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_b(t_data *data)
{
	int len;
	int pivot;
	t_stack *piv;

	piv = data->median;
	if(piv == NULL)
	{
		ft_find_pivot_ab(data);
		pivot = data->pivot_b;
	}
	else 
	{
		pivot = piv->nb;
		piv = piv->next;
	}
	ft_size_stack_ab(data);
	len = 0;
	ft_stack_is_sort_b(data);
	if (data->size_b < 4 || data->b->sort == 2)
	{
		print_pivot(data->median);
		ft_quick_sort_last_b(data);
		return;
	}

	while (len < data->size_b && ft_something_push_b(data->a,data->pivot_a) && data->b->sort != 1)
	{
		if (data->b->nb >= data->pivot_b)
			ft_pa(data);
		else
			ft_rb(data);
		len++;
	}	
	ft_quick_sort_b(data);
}

void	ft_quick_sort_a(t_data *data)
{
	t_stack *pivot;
	int len;

	ft_find_pivot_ab(data);
	ft_size_stack_ab(data);
	len = 0;
	ft_stack_is_sort_a(data);
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
	//print_list(data->a,data->b);
	ft_index(data);
	printf("int min = %d et int max =%d\n",data->min, data->max);
	stack_is_sort(data);
	ft_quick_sort_a(data);
	stack_is_sort(data);
	print_list(data->a,data->b);
	return (0);
}