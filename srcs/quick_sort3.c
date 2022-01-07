/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:31:46 by jremy             #+#    #+#             */
/*   Updated: 2022/01/07 19:19:36 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_quick_sort_last_b(t_data *data)
{
	int i;
	int j;
	int k;

	printf("quick_sort_last_b\n");
	print_list(data->a,data->b);

	i = data->b->nb;
	j = data->b->next->nb;
	k = data->b->next->next->nb;
	if( i > j && j > k)
		return ;
	if (i > j && j > k)
		ft_rrb(data);
	if (i < j && j > k && k > i)
		ft_rb(data);
	if (i > j && j < k)
	{
		ft_pa(data);
		ft_rb(data);
		ft_pb(data);
	}	
	if (i < j && j < k)
	{
		ft_rrb(data);
		ft_rrb(data);
	}
	if( i < j && j > k && k < i)
		ft_sb(data);
	return;
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
		return ;
	if (i > j && j < k && i < k)
		ft_sa(data);
	if (i < j && j > k && i > k)
		ft_rra(data);
	if (i > j && j > k && i > k)
	{
		ft_sa(data);
		ft_rra(data);
	}
	if (i < j && j > k && i < k)
	{
		ft_rra(data);
		ft_sa(data);
	}
	if (i > j && j < k && i > k)
		ft_ra(data);
	ft_stack_is_sort(data->a);

	//ft_quick_sort_b(data);
}