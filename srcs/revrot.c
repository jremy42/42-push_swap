/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:27:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 19:08:41 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate_a(t_data *data)
{
	t_stack	*tmp;
	t_stack *tmp2;
	int		i;

	ft_size_stack(data);
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
	ft_stack_add_front(&data->a, tmp2);
}

void	ft_revrotate_b(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	ft_size_stack(data);
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
	ft_stack_add_front(&data->b, tmp2);
}

void	ft_revrotate_ab_a(t_data *data)
{
	t_stack	*tmp;
	t_stack *tmp2;
	int		i;

	ft_size_stack(data);
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
	ft_stack_add_front(&data->a, tmp2);
}

void	ft_revrotate_ab_b(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	ft_size_stack(data);
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
	ft_stack_add_front(&data->b, tmp2);
}

void	ft_revrotate_ab(t_data *data)
{
	ft_revrotate_a(data);
	ft_revrotate_b(data);
}