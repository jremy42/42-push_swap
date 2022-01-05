/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:10:39 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 12:51:50 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap_a(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	return (stack);
}


t_stack	*ft_swap_b(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	return (stack);
}


t_stack	*ft_swap_ab(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	return (stack);
}