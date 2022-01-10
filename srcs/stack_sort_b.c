/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:42:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 12:52:47 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sort_b(t_stack *stack, int min)
{
	t_stack *tmp;

	tmp = stack;
	printf("is_sort\n");
	while (tmp->next != NULL)
	{
		if (tmp->index +1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->nb == min)
		return (1);
	return (0);
}

void ft_insert_sort_b(t_stack *stack)
{
	t_stack *tmp;
	
	printf("insert_sort\n");
	tmp = stack;
	while (tmp != NULL)
	{
		tmp->sort = 2;
		tmp = tmp->next;
	}
	return ;
}

int ft_stack_is_sort_b(t_data *data)
{
	t_stack	*tmp;
	int		i;
	int 	size;

	i = 0;
	size = ft_size_stack(data->b);
	tmp = data->b;
	printf("stack_is_sort\n");
	while(tmp->next != NULL)
	{
		if(ft_is_sort_b(tmp, data->min) == 1)
			ft_insert_sort_b(tmp);
		tmp = tmp->next;
	}
	return (0);
}