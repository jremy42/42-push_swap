/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/17 18:41:51 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*__copy_stack(t_stack *stack)
{
	t_stack	*new;
	t_stack	*tmp;

	new = NULL;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		tmp = __stacknew(&stack->nb);
		tmp->index = stack->index;
		if (!tmp)
			return (NULL);
		__stackadd_back(&new, tmp);
		stack = stack->next;
	}
	return (new);
}

t_cmd	*__copy_cmd(t_cmd *cmd)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = NULL;
	if (!cmd)
		return (NULL);
	while (cmd != NULL)
	{	
		tmp = __cmdnew(cmd->cmd);
		if (!tmp)
			return (NULL);
		__cmdadd_back(&new, tmp);
		cmd = cmd->next;
	}
	return (new);
}

t_data	*__copy_data(t_data *data, t_data *new)
{
	new->size_a = data->size_a;
	new->a = __copy_stack(data->a);
	new->b = __copy_stack(data->b);
	new->cmd = __copy_cmd(data->cmd);
	return (new);
}

void	__free_cmd(t_data *data)
{
	t_cmd	*tmp;

	while (data->cmd != NULL)
	{
		tmp = data->cmd->next;
		free(data->cmd);
		data->cmd = tmp;
	}
	return ;
}

void	__free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->a)
		__free_stack(data->a);
	if (data->b)
		__free_stack(data->b);
	__free_cmd(data);
}
