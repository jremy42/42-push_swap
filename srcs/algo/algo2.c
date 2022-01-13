/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/13 10:29:58 by jremy            ###   ########.fr       */
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
	int rotate;
	int next_index;

	next_index = __find_min(data->a);
	size = __pivot_size(data->a);
	__size_stack_ab(data);
	len = 0;
	rotate = 0;	
	while (len < size && __something_push_a(data->a, pivot))
	{
		if (data->a->index == next_index && rotate == 0)
		{
			data->a->sort = 2;
			__ra(data);
			next_index++;
		}
		if (data->a->nb < pivot)
			__pb(data);
		else
		{
			__ra(data);
			rotate ++;
		}
		if (data->a->sort == 2)
		{
			// a optimiser 
			while (data->a->sort != 2)
				__ra(data);
			break ;
		}
		len++;
	}
	__first_sort_b(data);
}

void	__second_sort_a(t_data *data)
{
	
	
	while(data->a->sort == 0)
	{
		
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
	while (1)
	{
	pivot = __find_first_pivot(data);
	__first_sort_a(data, pivot);
	if (__repush_a(data, __first_insert(data, __find_min(data->b),__find_max(data->b))) == 1)
		break ;
	}

		
	while (data->a->index != 0)
			__ra(data);
	print_list(data->a, data->b);
	print_cmd_lst(data->cmd);	
	return (0);
}