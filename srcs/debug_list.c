/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:03:48 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 16:44:06 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	printf("stack_a | stack_b\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if(stack_a != NULL)
		{
			printf(" %d ",stack_a->nb);
			stack_a = stack_a->next;
		}
		printf(" | ");
		if(stack_b != NULL)
		{
			printf("  %d  ", stack_b->nb);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
}

void	print_stack(t_stack *stack_a)
{
	printf("stack_a \n");
	while (stack_a != NULL)
	{
			printf(" %d ",stack_a->nb);
			stack_a = stack_a->next;
		printf("\n");
	}
}