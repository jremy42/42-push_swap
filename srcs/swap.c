/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:10:39 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 18:45:51 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_data *data)
{
	t_stack	*tmp;

	printf("sa\n");
	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = data->a->next;
	data->a->next = tmp;
	return ;
}

void	ft_swap_b(t_data *data)
{
	t_stack	*tmp;

	printf("sb\n");
	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->b->next;
	data->b->next = tmp;
	return ;
}

void	ft_swap_ab_a(t_data *data)
{
	t_stack	*tmp;
	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = data->a->next;
	data->a->next = tmp;
	return ;
}

void	ft_swap_ab_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->b->next;
	data->b->next = tmp;
	return ;
}

void	ft_swap_ab(t_data *data)
{
	printf("ss\n");
	ft_swap_ab_a(data);
	ft_swap_ab_b(data);
	return ;
}