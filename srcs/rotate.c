/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:06:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 16:11:49 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__ra(t_data *data)
{
	t_stack	*tmp;

	printf("ra\n");
	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	__stackadd_back(&data->a, tmp);
}

void	__rb(t_data *data)
{
	t_stack	*tmp;

	printf("rb\n");
	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	__stackadd_back(&data->b, tmp);
}

void	__rr_a(t_data *data)
{
	t_stack	*tmp;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	__stackadd_back(&data->a, tmp);
}

void	__rr_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	__stackadd_back(&data->b, tmp);
}

void	__rr(t_data *data)
{
	printf("rr\n");
	__rr_b(data);
	__rr_a(data);
}
