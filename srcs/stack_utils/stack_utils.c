/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:58:42 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 14:47:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*__stacknew(int *content)
{
	t_stack	*newlst;

	newlst = malloc(sizeof(t_stack));
	if (!newlst)
		return (NULL);
	newlst->nb = *content;
	newlst->index = 0;
	newlst->sort = 0;
	newlst->next = NULL;
	return (newlst);
}

int	is_present(int nb, t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		if (stack->nb == nb)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

t_cmd	*__cmdnew(int cmd)
{
	t_cmd	*newlst;

	newlst = malloc(sizeof(t_cmd));
	if (!newlst)
		return (NULL);
	newlst->cmd = cmd;
	newlst->next = NULL;
	return (newlst);
}

void	__cmdadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*nextlst;

	if (!(*alst))
		*alst = new;
	else
	{
		nextlst = (*alst);
		while (nextlst->next)
			nextlst = nextlst->next;
		nextlst->next = new;
	}
}

int	__insert_cmd(t_data *data, int op)
{
	t_cmd	*new;

	new = __cmdnew(op);
	if (!new)
		return (-1);
	__cmdadd_back(&data->cmd, new);
	return (0);
}

