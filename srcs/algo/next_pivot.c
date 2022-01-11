/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:22:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 18:39:19 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int __index_max(t_stack *stack)
{
    int index;
    t_stack *tmp;

    tmp = stack;
    index = stack->index;

    while (tmp != NULL)
    {
        if (tmp->index > index)
            index = tmp->index;
        tmp = tmp->next;
    }
    return (index);
}

int __kth_pivot(t_stack *stack, int index_max)
{
    t_stack *tmp;
    int next_pivot;

    //printf("index max = %d\n",index_max);
    next_pivot = 0;
    tmp = stack;
    while (tmp->index != index_max)
        tmp = tmp->next;
    while (tmp != NULL)
    {
        if (tmp->index == index_max - 1 ||
        tmp->index == index_max)
        {
            index_max = tmp->index;
            next_pivot = tmp->nb;
        }
        tmp = tmp->next;
    }
    return (next_pivot);
}

int __next_pivot(t_stack *stack)
{
    int next_pivot;

    if (!stack)
        return (0);
    next_pivot = __kth_pivot(stack, __index_max(stack));
    return (next_pivot);
}