/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 17:48:19 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	ft_parsing(av, &data);
	//print_list(data.a, data.b);
	ft_swap_a(&data);
	//printf("======\n");
	//print_list(data.a, data.b);
	ft_push_a(&data);
	ft_push_a(&data);
	ft_push_a(&data);
	ft_push_a(&data);
	//printf("======\n");
	//print_list(data.a, data.b);
	ft_swap_ab(&data);
	printf("======\n");
	print_list(data.a, data.b);
	ft_rotate_ab(&data);
	printf("======\n");
	print_list(data.a, data.b);
	ft_size_stack(&data);
	printf(" stack_a = %d\n stack_b = %d\n",data.size_a, data.size_b);
	printf("======\n");
	print_list(data.a, data.b);
	ft_revrotate_a(&data);
}