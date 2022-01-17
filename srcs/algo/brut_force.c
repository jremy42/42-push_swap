/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 17:42:12 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack *__copy_stack(t_stack *stack)
{
	t_stack *new;
	t_stack *tmp;

	new = NULL;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		tmp = __stacknew(stack->nb);
		if (!new)
			return (NULL);
		__stackadd_back(&new, tmp);
		stack = stack->next;
	}
	return (new);
}

t_data *__copy_data(t_data *data, t_data *copy)
{
	new->a = __copy_stack(data->a);
	new->b = __copy_stack(data->b);
	__index(copy);
}

void __free_data(t_data *data)
{
	t_data	*tmp;

	if (!data)
		return ;
	while (data != NULL)
	{
		tmp = (data)->next;
		free(data);
		data = tmp;
	}
	free(data);
}

void __under_6(t_data *data)
{
	t_data *copy;
	copy = __copy_stack(data, copy);


	if(!copy)
		return (NULL);

	while (1)
	{
		if(__sort_bf(copy) == 1)
			break;
		__bf(copy, );
		else
		{
			__free_data(copy);
			copy = __copy_stack(data);
		}
		
	}
}
