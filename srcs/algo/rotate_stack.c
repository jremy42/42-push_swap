/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:49:15 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 17:15:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__rotate_stack_a(t_data *data)
{
	int i;
	int j;
	t_stack *tmp;

	tmp = data->a;
	i = 0;
	j = 0;
	while (tmp != NULL)
	{
		//printf("tmp->sort ==%d\n",tmp->sort);
		if (tmp->sort == 1)
			i++;
		tmp = tmp->next;
		j++;
	}
	//printf(" i = %d et j = %d\n",i,j);
	if ( (j - 1) == i)
		__quick_sort_b(data);
	else
		{
			while(data->a->sort == 1)
				__rb(data);
			return ;
		}
}
