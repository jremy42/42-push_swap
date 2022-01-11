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
	while (i < size - 2)
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
	while (i < size - 2)
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

	if (i == 0)
		return (tab[i + 1]);
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
	if (!stack || size == 0)
		return (0);
	tmp = stack;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	while (tmp != NULL && i < size)
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
	if (!stack || size == 0)
		return (0);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	while (tmp->next != NULL && i < size)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	data->pivot_b = __pivot_b(tab, size);
	return (0);
}

int	__pivot_size(t_stack *stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp != NULL && tmp->sort < 1)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int __find_pivot_ab(t_data *data)
{
	__size_stack_ab(data);
	//printf("data->size_a %d et size_pivot %d \n",data->size_a,__pivot_size(data->a));
	if (data->a)
		__find_pivot_a(data->a, __pivot_size(data->a), data);
	if (data->b)
		__find_pivot_b(data->b, __pivot_size(data->b), data);
	//print_list(data->a,data->b);
	//printf("pivot a = %d\n",data->pivot_a);
	//printf("pivot b = %d\n",data->pivot_b);
	return (1);
}