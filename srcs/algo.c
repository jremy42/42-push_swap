/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 19:40:51 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_quick_sort_last_b(t_data *data)
{
	int i;
	int j;
	int k;

	i = data->b->nb;
	j = data->b->next->nb;
	k = data->b->next->next->nb;
	if( i < j && j < k)
		return ;
	if (i > j && j > k)
		ft_revrotate_b(data);
	if (i < j && j > k && k > i)
		ft_rotate_b(data);
	if (i > j && j < k)
	{
		ft_push_b(data);
		ft_rotate_b(data);
		ft_push_a(data);
	}	
	if (i < j && j < k)
	{
		ft_revrotate_b(data);
		ft_revrotate_b(data);
	}
	if( i < j && j > k && k < i)
		ft_swap_b(data);
	ft_push_b(data);
	ft_push_b(data);
	ft_push_b(data);
	return;
}


void ft_quick_sort_b(t_data *data)
{
	int tmp;
	int 	i;

	i = 0;
	tmp = 0;

	ft_find_median_ab(data);
	print_list(data->a,data->b);

	if(data->size_b < 4)
	{
		ft_quick_sort_last_b(data);
		return;
	}
	while(tmp != data->b->nb )
	{
		if (data->b->nb <= data->median_b)
		{ 
			if (i == 0)
				{
					tmp = data->b->nb;
					i++;
				}
			ft_rotate_b(data);
		}
		else
			ft_push_b(data);
	}
		ft_quick_sort_b(data);
}

void ft_quick_sort_last_a(t_data *data)
{
	int i;
	int j;
	int k;

	i = data->a->nb;
	j = data->a->next->nb;
	k = data->a->next->next->nb;
	if( i < j && j < k)
		ft_quick_sort_b(data);
	if (i < j && j > k)
	{
		ft_rotate_a(data);
		ft_rotate_a(data);
	}	
	if( i > j && j < k && k > i)
		ft_swap_a(data);

	ft_quick_sort_b(data);
}

void ft_quick_sort_a(t_data *data)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;

	ft_find_median_ab(data);
	printf("data->size_a = %d\n median = %d\n", data->size_a, data->median_a);
	print_stack(data->a);
	if(data->size_a < 4)
	{
		ft_quick_sort_last_a(data);
		return;
	}
	while (tmp != data->a->nb || ft_something_push(data) == 1)
	{
		if (data->a->nb < data->median_a)
			ft_push_a(data);
		else
		{
			if (i == 0)	
			{
				tmp = data->a->nb;
				i++;
			}
			ft_rotate_a(data);
		}
					//if (ft_tmp_sort(data) == 1)
			//ft_quick_sort_b(data);
	}
		ft_quick_sort_a(data);
}
int ft_algo(t_data *data)
{
	//print_stack(data->a);
	ft_find_median_ab(data);
	stack_is_sort(data);
	ft_quick_sort_a(data);
	stack_is_sort(data);
	print_list(data->a,data->b);
	return (0);
}