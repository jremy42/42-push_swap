/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:27:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 17:54:26 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate_a(t_data *data)
{
	t_stack	*tmp;
	int		i;

	if (!data->a)
		return ;
	i = 0;
	ft_size_stack(data);
	tmp = data->a;
	while(i + 1 < data->size_a)
	{
		tmp = tmp->next;
		i++;
	}
	printf("tmp = %d \n",tmp->nb);
	
/*	
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	ft_stackadd_back(&data->a, tmp);
	*/
}