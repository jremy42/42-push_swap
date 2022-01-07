/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:04:50 by jremy             #+#    #+#             */
/*   Updated: 2022/01/07 19:22:42 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_something_push_a(t_stack *stack, int pivot)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->nb <= pivot)
            return (1);
        tmp = tmp->next;
    }
    return (-1);
}

int ft_something_push_b(t_stack *stack, int pivot)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->nb >= pivot)
            return (1);
        tmp = tmp->next;
    }
    return (-1);
}

int ft_size_stack(t_stack *stack)
{
	t_stack *tmp;
	int		a;

	a = 0;	
	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		a++;
	}
	return (a);
}

int ft_is_sort(t_stack *stack)
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
	return (1);
}

void ft_insert_sort(t_stack *stack)
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

int ft_stack_is_sort(t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int 	size;

	i = 0;
	size = ft_size_stack(stack);
	tmp = stack;
	printf("stack_is_sort\n");
	while(tmp->next != NULL)
	{
		if(ft_is_sort(tmp) == 1)
			ft_insert_sort(tmp);
		tmp = tmp->next;
	}
	return (0);
}