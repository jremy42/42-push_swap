/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:22:25 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 18:39:19 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_median(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		if(tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	i = 0;	
	if ((size - 1) % 2 == 0)
		return (tab[size / 2]);
	else
		return(tab[(size / 2) + 1]);
}

int ft_find_median_a(t_stack *stack, int size, t_data *data)
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
	while (tmp->next != NULL)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	data->median_a = ft_median(tab, size);
	free(tab);
	return (0);
}

int ft_find_median_b(t_stack *stack, int size, t_data *data)
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
	data->median_b = ft_median(tab, size);
	return (0);
}

int ft_find_median_ab(t_data *data)
{
	ft_size_stack(data);
	if (data->a)
		ft_find_median_a(data->a, data->size_a, data);
	if (data->b)
		ft_find_median_b(data->b, data->size_b, data);
	return (1);
}