/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:42:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 14:58:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int __is_sort_a(t_stack *stack, int max)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->index +1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->nb == max)
		return (1);
	return (0);
}

void __insert_sort_a(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->sort = 1;
		tmp = tmp->next;
	}
	return ;
}

int __stack_is_sort_a(t_data *data)
{
	t_stack	*tmp;
	int		i;
	int 	size;

	i = 0;
	size = __size_stack(data->a);
	tmp = data->a;
	while(tmp->next != NULL)
	{
		if(__is_sort_a(tmp, data->max) == 1)
			__insert_sort_a(tmp);
		tmp = tmp->next;
	}
	return (0);
}