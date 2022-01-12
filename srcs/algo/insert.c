/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:13:09 by jremy             #+#    #+#             */
/*   Updated: 2022/01/12 08:19:01 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void __repush_a(t_data *data, int next_index)
{
	//printf("next_index = %d", next_index);
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



int	__first_insert(t_data *data, int next_index)
{
	int rotate;

	if (!data->b)
		return (next_index);
	rotate = __cost_calculatore(data->b, next_index);
	if (rotate == 1)
	{
		while (data->b->index != next_index)
		{
			__prisongot(data);
			__rb(data);
			__reinsertion(data);
		}
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
	
	return (__first_insert(data, next_index + 1));
}
