/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:58:42 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 12:06:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int *content)
{
	t_stack	*newlst;

	newlst = malloc(sizeof(t_stack));
	if (!newlst)
		return (NULL);
	newlst->nb = *content;
	newlst->min = 0;
	newlst->max = 0;
	newlst->index = 0;
	newlst->cmd = NULL;
	newlst->next = NULL;
	return (newlst);
}

int	is_present(int nb, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->nb == nb)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

void	ft_stackadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*nextlst;

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
