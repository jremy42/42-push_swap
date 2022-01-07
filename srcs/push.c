/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:10:39 by jremy             #+#    #+#             */
/*   Updated: 2022/01/07 10:14:25 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_data *data)
{
	t_stack	*tmp;

	printf("pb\n");
	if (!data->a)
		return ;
	tmp = data->a->next;
	ft_stack_add_front(&data->b, data->a);
	data->a = tmp;
}

void	ft_pa(t_data *data)
{
	t_stack	*tmp;

	printf("pa\n");
	if (!data->b)
		return ;
	tmp = data->b->next;
	ft_stack_add_front(&data->a, data->b);
	data->b = tmp;
}
