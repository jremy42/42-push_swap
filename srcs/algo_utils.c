/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:04:50 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 12:48:46 by jremy            ###   ########.fr       */
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
