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

int __pivot_a(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		j++;
		}
		j = 0;
		i++;
	}
	if (size % 2 == 0)
		return (tab[(size / 2) - 1]);	
	return (tab[size / 2]);	
}

int __pivot_b(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		j++;
		}
		j = 0;
		i++;
	}
	if (size % 2 == 0)
		return (tab[(size / 2) + 1]);	
	return (tab[size / 2]);	
}

int __find_pivot_a(t_stack *stack, int size, t_data *data)
{
	int i;
	int *tab;
	t_stack *tmp;

	i = 0;
	if (!stack)
		return (0);
	tmp = stack;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	while (tmp != NULL)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	data->pivot_a = __pivot_a(tab, size);
	free(tab);
	return (0);
}

int __find_pivot_b(t_stack *stack, int size, t_data *data)
{
	int i;
	int *tab;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	if (!stack)
		return (0);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	while (tmp->next != NULL)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	data->pivot_b = __pivot_b(tab, size);
	return (0);
}

int __find_pivot_ab(t_data *data)
{
	__size_stack_ab(data);
	if (data->a)
		__find_pivot_a(data->a, data->size_a, data);
	if (data->b)
		__find_pivot_b(data->b, data->size_b, data);
	return (1);
}