/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:42:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 12:52:31 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sort_a(t_stack *stack, int max)
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
	if (tmp->nb == max)
		return (1);
	return (0);
}

void ft_insert_sort_a(t_stack *stack)
{
	t_stack *tmp;
	
	printf("insert_sort\n");
	tmp = stack;
	while (tmp != NULL)
	{
		tmp->sort = 1;
		tmp = tmp->next;
	}
	return ;
}

int ft_stack_is_sort_a(t_data *data)
{
	t_stack	*tmp;
	int		i;
	int 	size;

	i = 0;
	size = ft_size_stack(data->a);
	tmp = data->a;
	printf("stack_is_sort\n");
	while(tmp->next != NULL)
	{
		if(ft_is_sort_a(tmp, data->max) == 1)
			ft_insert_sort_a(tmp);
		tmp = tmp->next;
	}
	return (0);
}