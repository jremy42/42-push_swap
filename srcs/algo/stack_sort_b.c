/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:42:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/11 17:05:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int __is_sort_b(t_stack *stack, int min)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->index - 1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->nb == min)
		return (1);
	return (0);
}

void __insert_sort_b(t_stack *stack)
{
	t_stack *tmp;
	
	tmp = stack;
	while (tmp != NULL)
	{
		tmp->sort = 2;
		tmp = tmp->next;
	}
	return ;
}

int __stack_is_sort_b(t_data *data)
{
	t_stack	*tmp;
	int		i;
	int 	size;

	i = 0;
	size = __size_stack(data->b);
	if (data->size_b < 2)
		return (0);
	tmp = data->b;
	while(tmp->next != NULL)
	{
		if(__is_sort_b(tmp, data->min) == 1)
			__insert_sort_b(tmp);
		tmp = tmp->next;
	}
	return (0);
}