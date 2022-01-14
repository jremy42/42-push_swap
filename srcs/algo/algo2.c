/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:46:04 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 09:18:26 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__first_sort_b(t_data *data)
{
	int len;
	int size;

	size = __pivot_size(data->b);
	__find_pivot_ab(data);

	len = 0;
	//printf("pivot = %d\n", data->pivot_b);
	while (len < size && __something_push_b(data->b, data->pivot_b))
	{
		if (data->b->nb > data->pivot_b)
		{
			data->b->sort = 1;
			__pa(data);
		}
		else
			__rb(data);
		len++;
	}
}


void	__first_sort_a(t_data *data, int pivot)
{
	int len;
	int size;
	int rotate;
	int next_index;

	next_index = __find_min(data->a);
	//printf("pivot = %d\n",pivot);
	size = __pivot_size(data->a);
	__size_stack_ab(data);
	len = 0;
	rotate = 0;	
	while (len < size && __something_push_a(data->a, pivot))
	{
		if (data->a->index == next_index && rotate == 0)
		{
			data->a->sort = 2;
			__ra(data);
			next_index++;
		}
		if (data->a->nb < pivot)
			__pb(data);
		else
		{
			__ra(data);
			rotate ++;
		}
		if (data->a->sort == 2)
		{
			// a optimiser 
			while (data->a->sort != 2)
				__ra(data);
			break ;
		}
		len++;
	}
	printf("=== end first a ======\n");
	//print_list(data->a, data->b);
	__first_sort_b(data);
}

void	__second_sort_a(t_data *data)
{
	
	
	while(data->a->sort == 0)
	{
		
		__pb(data);
	}
	__first_sort_b(data);	
}

int __nb_sort(t_stack *stack)
{
	int sort;
	t_stack *tmp;

	tmp = stack;
	sort = 0;
	while (tmp != NULL)
	{
		if (tmp->sort == 2)
			sort++;
		tmp = tmp->next;
	}
	return(sort);
}

int __size_stack_piv(t_stack *stack)
{
	t_stack *tmp;
	int		a;

	a = 0;	
	tmp = stack;
	while (tmp != NULL && tmp->sort != 2)
	{
		tmp = tmp->next;
		a++;
	}
	return (a);
}

int __find_pivot_chunks(t_data *data, int chunks)
{
	t_stack *tmp;
	
	tmp = data->a;
	while (tmp != NULL)
	{
		if(tmp->index == chunks)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int __size_chunks(t_data *data)
{
	t_stack *tmp;
	int size;
	int i;

	tmp = data->a;
	i = 0;	
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	
	data->size_final = i;
	size = i / NB_CHUNKS;
	return (size);
}

/*
int __algo2(t_data *data)
{
	int		pivot;
	int		chunks;
	int		min;
	
	__index(data);
	chunks = __size_chunks(data);
	min = __find_mind(data->a);
	while (chunks <= data->size_final)
	{
		//printf("===========================chunks = %d=====================\n",chunks);
		pivot = __find_pivot_chunks(data, chunks);
		//print_list(data->a, data->b);
		__first_sort_a(data, pivot);
		//print_list(data->a, data->b);
		__repush_a(data, __first_insert(data, __find_min(data->b),__find_max(data->b)));
		//print_list(data->a, data->b);
		__repush_a(data, __first_insert(data, __find_min(data->b),__find_max(data->b)));
		//print_list(data->a, data->b);
		chunks += chunks;
	}
	print_list(data->a, data->b);
	while (data->a->index != 0)
			__ra(data);
	//print_cmd_lst(data->cmd);
	print_list(data->a, data->b);
	return (0);
}
*/