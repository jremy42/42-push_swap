/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:27:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 18:35:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__rra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	__size_stack_ab(data);
	if (!data->a || data->size_a < 2)
		return ;
	__insert_cmd(data, RRA);
	i = 0;
	tmp = data->a;
	while (i + 2 < data->size_a)
	{
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->next;
	tmp->next = NULL;
	__stack_add_front(&data->a, tmp2);
}

void	__rrb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	__size_stack_ab(data);
	if (!data->b || data->size_b < 2)
		return ;
	__insert_cmd(data, RRB);
	i = 0;
	tmp = data->b;
	while (i + 2 < data->size_b)
	{
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->next;
	tmp->next = NULL;
	__stack_add_front(&data->b, tmp2);
}

void	__rrr_a(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	__size_stack_ab(data);
	if (!data->a || data->size_a < 2)
		return ;
	i = 0;
	tmp = data->a;
	while (i + 2 < data->size_a)
	{
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->next;
	tmp->next = NULL;
	__stack_add_front(&data->a, tmp2);
}

void	__rrr_b(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	__size_stack_ab(data);
	if (!data->b || data->size_b < 2)
		return ;
	i = 0;
	tmp = data->b;
	while (i + 2 < data->size_b)
	{
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->next;
	tmp->next = NULL;
	__stack_add_front(&data->b, tmp2);
}

void	__rrr(t_data *data)
{
	__rra(data);
	__rrb(data);
}
