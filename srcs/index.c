/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:13:19 by jremy             #+#    #+#             */
/*   Updated: 2022/01/07 17:01:19 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_insert_index(t_data *data, int *tab)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = data->a;
	while (tmp != NULL)
	{
		while(i < data->size_a)
		{
			if(tmp->nb == tab[i])
				tmp->index = i;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}

}

void ft_sort(t_data *data, int *tab)
{
	int i;
	int j;
	int tmp;
	int size;

	size = data->size_a;
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
	ft_insert_index(data, tab);
}

int ft_index(t_data *data)
{
	int i;
	int *tab;
	t_stack *tmp;

	i = 0;
	if (!data->a)
		return (0);
	tmp = data->a;
	ft_size_stack_ab(data);
	tab = malloc(sizeof(int) * data->size_a);
	if (!tab)
		return (-1);
	while (tmp != NULL)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	ft_sort(data,tab);
	free(tab);
	return (0);
}