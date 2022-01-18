/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:17:48 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 16:46:01 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__error(char *error, t_data *data)
{
	int	len;

	len = __strlen(error);
	write(2, error, len);
	__exit_ps(data, 1);
}

void	__free_stack(t_stack *stack)
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

void	__exit_ps(t_data *data, int error)
{
	if (data->a)
		__free_stack(data->a);
	if (data->b)
		__free_stack(data->b);
	if (data->cmd)
		__free_cmd(data);
	//system("leaks checker");
	exit(error);
}
