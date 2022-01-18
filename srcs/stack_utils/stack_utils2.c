/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:35:32 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 14:47:22 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__stack_add_front(t_stack **alst, t_stack *new)
{
	if (!*alst)
		new->next = NULL;
	else
		new->next = (*alst);
	(*alst) = new;
}

void	__size_stack_ab(t_data *data)
{
	t_stack	*tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tmp = data->a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		a++;
	}
	tmp = data->b;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		b++;
	}
	data->size_a = a;
	data->size_b = b;
}

void	__size_stack_pivot(t_data *data)
{
	t_stack	*tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tmp = data->a;
	while (tmp != NULL && tmp->sort != 1)
	{
		tmp = tmp->next;
		a++;
	}
	tmp = data->b;
	while (tmp != NULL && tmp->sort != 2)
	{
		tmp = tmp->next;
		b++;
	}
	data->size_a = a;
	data->size_b = b;
}

int	__tmp_sort(t_data *data)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	__size_stack_ab(data);
	tmp = data->a;
	while (tmp->next != NULL)
	{
		if (tmp->nb < tmp->next->nb)
			i++;
		tmp = tmp->next;
	}
	if (i == data->size_a - 1)
		return (1);
	return (0);
}

void	__stackadd_back(t_stack **alst, t_stack *new)
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