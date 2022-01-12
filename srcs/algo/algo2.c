/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/12 09:53:15 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__first_sort_b(t_data *data)
{
	int len;
	int size;

	size = __pivot_size(data->b);
	__find_pivot_ab(data);

	len = 0;
	//printf("pivot = %d\n", data->pivot_b);
	while (len < size && __something_push_b(data->b, data->pivot_b))
	{
		if (data->b->nb > data->pivot_b)
		{
			data->b->sort = 1;
			__pa(data);
		}
		else
			__rb(data);
		len++;
	}
}


void	__first_sort_a(t_data *data, int pivot)
{
	int len;
	int size;

	size = __pivot_size(data->a);
	//__find_pivot_ab(data);
	__size_stack_ab(data);
	len = 0;
	
	while (len < size && __something_push_a(data->a, pivot))
	{
		if (data->a->nb < pivot)
		{
			__pb(data);
			//__hight_list_check(data);
		}
		else
			__ra(data);
		len++;
	}
	__first_sort_b(data);
}

void	__second_sort_a(t_data *data)
{
	int next_index;
	
	next_index = __find_min(data->a);
	
	while(data->a->sort == 0)
	{
		if(data->a->index == next_index)
		{
			data->a->sort = 2;	
			__ra(data);
			next_index++;
		}
		__pb(data);
	}
	__first_sort_b(data);	
}

int __find_first_pivot(t_data *data)
{
	t_stack *tmp;

	tmp = data->a;

	while (tmp != NULL)
	{
		if(tmp->index == PIVOT)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int __algo2(t_data *data)
{
	int		pivot;

	
	__index(data);
	pivot = __find_first_pivot(data);
	__first_sort_a(data, pivot);
	printf("algo2\n");
	print_list(data->a, data->b);
	__repush_a(data, __first_insert(data, 0,__find_max(data->b)));	
	while(data->a->index != 0)
	{
		__repush_a(data,__first_insert(data,__find_min(data->b),__find_max(data->b)));
		print_list(data->a, data->b);
		__second_sort_a(data);
		print_list(data->a, data->b);
		__repush_a(data,__first_insert(data,__find_min(data->b),__find_max(data->b)));
		print_list(data->a, data->b);
		__first_insert(data,__find_min(data->b), __find_max(data->b));
		while (data->a->index != 0)
			__ra(data);
	}
	print_list(data->a, data->b);
	print_cmd_lst(data->cmd);	
	return (0);
}