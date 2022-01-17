/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:17:48 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:55:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void __free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}

void __exit_ps(t_data *data, int error)
{
	//print_list(data->a, data->b);
	if (data->a)
		__free_stack(data->a);
	if (data->b)
		__free_stack(data->b);
	if (data->cmd)
	{
		print_cmd_lst(data->cmd);
		__free_cmd(data);
	}
	//system("leaks push_swap");
	exit(error);
}
