/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:04:50 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 10:37:40 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int __something_push_a(t_stack *stack, int pivot)
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

int __something_push_b(t_stack *stack, int pivot)
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

int __size_stack(t_stack *stack)
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