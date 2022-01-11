/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 18:38:03 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__quick_sort_b(t_data *data)
{
	int len;
	int pivot;	
	pivot = __next_pivot(data->b);
	__size_stack_ab(data);
	len = 0;
	__stack_is_sort_b(data);
	
	if (pivot == 0)
	{
		__pa(data);
		return;
	}
	/*
	if (data->size_b < 4 || data->b->sort == 2)
	{
		if (data->size_b == 2)
			__pb(data);
		__quick_sort_last_b(data);
		return;
	}
	*/
	printf("pivot =%d\n",pivot);
	print_list(data->a,data->b);
	while (__something_push_b(data->b, pivot) != -1 && pivot != 0)
	{
		if (data->b->nb >= pivot)
		{
			__pa(data);
			if (data->a->nb == pivot)
				__ra(data);
			else if (data->a->nb > data->a->next->nb)
				__sa(data);
		}
		else
			__rb(data);
		__size_stack_ab(data);
		len++;
	}
	if (__something_push_b(data->b, pivot) == -1 && len > 0 )
		__rra(data);
	
	__quick_sort_b(data);
	return ;
}

void	__quick_sort_a(t_data *data)
{
	t_stack *pivot;
	int len;

	__find_pivot_ab(data);
	__size_stack_ab(data);
	len = 0;
	__stack_is_sort_a(data);
	if (data->a->sort == 1 || data->size_a < 4)
	{
		__quick_sort_last_a(data);
		return;
	}

	while (len < data->size_a && __something_push_a(data->a,data->pivot_a) && data->a->sort != 1)
	{
		if (data->a->nb < data->pivot_a)
		{
			__pb(data);
			if (data->b->next != NULL)
				if (data->b->nb < data->b->next->nb)
					__sb(data);
		}
		else
			__ra(data);
		len++;
	}
	pivot = __stacknew(&data->pivot_a);
	__stack_add_front(&data->median, pivot);
	__rotate_stack_a(data);
	__quick_sort_a(data);
}

int __algo(t_data *data)
{
	//print_list(data->a,data->b);
	__index(data);
	////printf("int min = %d et int max =%d\n",data->min, data->max);
	stack_is_sort(data);
	__quick_sort_a(data);
	//stack_is_sort(data);
	//__stack_is_sort_a(data);
	//__stack_is_sort_b(data);
	print_list(data->a,data->b);
	return (0);
}