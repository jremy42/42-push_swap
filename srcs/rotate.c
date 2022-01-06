/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:06:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 18:46:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_data *data)
{
	t_stack	*tmp;

	printf("ra\n");
	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	ft_stackadd_back(&data->a, tmp);
}

void	ft_rotate_b(t_data *data)
{
	t_stack	*tmp;

	printf("rb\n");
	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	ft_stackadd_back(&data->b, tmp);
}

void	ft_rotate_ab_a(t_data *data)
{
	t_stack	*tmp;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	ft_stackadd_back(&data->a, tmp);
}

void	ft_rotate_ab_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	ft_stackadd_back(&data->b, tmp);
}

void	ft_rotate_ab(t_data *data)
{
		printf("rr\n");
	ft_rotate_ab_b(data);
	ft_rotate_ab_a(data);
}
