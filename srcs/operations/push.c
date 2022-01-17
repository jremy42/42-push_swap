/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:10:39 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 10:31:14 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	__hight_list_check(t_data *data)
{
	if (data->a->next == NULL)
		return ;
	if (!data->b || data->b->next == NULL)
		return ;
	//printf("coucou\n");
	//print_list(data->a, data->b);
	if (data->a->nb > data->a->next->nb
	&& data->b->nb < data->b->next->nb)
		__ss(data); 
	else 
	{
		if (data->a->nb > data->a->next->nb)
			__sa(data);
		if (data->b->nb < data->b->next->nb)
		 	__sb(data);
		else 
			return ;
	}
}

void	__pb(t_data *data)
{
	t_stack	*tmp;
	
	//printf("pb\n");
	if (!data->a)
		return ;
	__insert_cmd(data, PB);
	tmp = data->a->next;
	__stack_add_front(&data->b, data->a);
	data->a = tmp;
}

void	__pa(t_data *data)
{
	t_stack	*tmp;

	//printf("pa\n");
	if (!data->b)
		return ;
	__insert_cmd(data, PA);
	tmp = data->b->next;
	__stack_add_front(&data->a, data->b);
	data->b = tmp;
}
