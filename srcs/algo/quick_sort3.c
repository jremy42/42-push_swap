/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:31:46 by jremy             #+#    #+#             */
/*   Updated: 2022/01/11 18:42:48 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void __replace_b(t_data *data)
{
	while (data->a->index == data->b->index + 1)
		__pb(data);
	__stack_is_sort_b(data);
	return ;
}
void __quick_sort_last_b(t_data *data)
{
	int i;
	int j;
	int k;

	//printf("quick_sort_last_b\n");
	////print_list(data->a, data->b);

	i = data->b->nb;
	j = data->b->next->nb;
	k = data->b->next->next->nb;
	__stack_is_sort_b(data);
	if( i > j && j > k && i > k)
		__replace_b(data) ;
	else if (i > j && j < k && i < k)
		__rrb(data);
	if (i < j && j > k && k > i)
		__rb(data);
	if (i > j && j < k && i > k)
	{
		__pa(data);
		__rb(data);
		__pb(data);
	}	
	if (i < j && j < k && i < k)
	{
		__rb(data);
		__sb(data);
	}
	if( i < j && j > k && k < i)
		__sb(data);
	__replace_b(data);
}

void __quick_sort_last_a(t_data *data)
{
	int i;
	int j;
	int k;

	i = data->a->nb;
	j = data->a->next->nb;
	k = data->a->next->next->nb;
	
	if( i < j && j < k)
		__quick_sort_b(data);
	if (i > j && j < k && i < k)
		__sa(data);
	if (i < j && j > k && i > k)
	{
		__pb(data);
		__sa(data);
		__pa(data);
		__sa(data);
		//print_list(data->a,data->b);
		__quick_sort_b(data);

	}
	if (i > j && j > k && i > k)
	{
		__sa(data);
		__rra(data);
	}
	if (i < j && j > k && i < k)
	{
		__rra(data);
		__sa(data);
	}
	if (i > j && j < k && i > k)
		__ra(data);
	__stack_is_sort_a(data);

	__quick_sort_b(data);
}