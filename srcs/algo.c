/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 13:10:11 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_find_median(t_stack *stack, int size)
{
	int len;
	int kth;
	int min;
	t_stack *tmp;

	min = 0;
	len = 0;
	kth = size / 2;
	tmp = stack;
	while (len < size - 1 || tmp->next != NULL)
	{	
		if (tmp->nb < tmp->next->nb)
			min++;
		if (min == kth)
			return (tmp->nb);	
		tmp = tmp->next;
		len++;
	}
	return (0);
}

int ft_find_median_ab(t_data *data)
{
	ft_size_stack(data);
	if (data->a)
		data->median_a = ft_find_median(data->a, data->size_a);
	if (data->b)
		data->median_b = ft_find_median(data->b, data->size_b);
	return (1);
}
int ft_algo(t_data *data)
{
	print_stack(data->a);
	data->median_a = ft_find_median_ab(data);
	printf("median a = %d\n", data->median_a);
	return (0);
}