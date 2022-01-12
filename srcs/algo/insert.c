/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/12 09:40:07 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void __repush_a(t_data *data, int next_index)
{
	//printf("next_index = %d", next_index);
	while(data->a->sort == 2)
			__ra(data);
	while(data->a->sort == 1)
	{
		if(data->a->index == next_index)
		{	
			__ra(data);
			next_index++;
		}
		__pb(data);
		//__hight_list_check(data);
	}
	return ;
}

int __first_insert_min(t_data *data, int next_index)
{
		int rotate;

		rotate = __cost_calculatore(data->b, next_index);
		
	if (rotate == 1)
	{
		while (data->b->index != next_index)
			__rb(data);
		data->b->sort = 2;
		__pa(data);
		__ra(data);
		//__hight_list_check(data);
	}
	else 
	{
		while (data->b->index != next_index)
			__rrb(data);
		data->b->sort = 2;
		__pa(data);
		__ra(data);
		//__hight_list_check(data);
	}

		return (1);
}

int __first_insert_max(t_data *data, int max_index)
{
		int rotate;

		rotate = __cost_calculatore(data->b, max_index);
		
	if (rotate == 1)
	{
		while (data->b->index != max_index)
			__rb(data);
		data->b->sort = 2;
		__pa(data);
		//__hight_list_check(data);
	}
	else 
	{
		while (data->b->index != max_index)
			__rrb(data);
		data->b->sort = 2;
		__pa(data);
		//__hight_list_check(data);
	}

		return (1);
}

int	__first_insert(t_data *data, int next_index, int max_index)
{
	int min;
	int max;

	if (!data->b)
		return (next_index);
	min = 0;
	max = 0;
	//write(1,"NTM",3);
	//printf("next_index = %d et max_index = %d",next_index, max_index);
	if (__cost_index(data->b, next_index, max_index) == 1)
		min = __first_insert_min(data, next_index);
	else
		max = __first_insert_max(data, max_index);	
	return (__first_insert(data, next_index + min, max_index - max));
}
