/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 16:10:38 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	__parsing(av, &data);
	__algo(&data);
	/*
	//print_list(data.a, data.b);
	__sa(&data);
	////printf("======\n");
	//print_list(data.a, data.b);
	//printf("2\n");
	__pb(&data);
	__pb(&data);
	__pb(&data);
	////printf("======\n");
	//print_list(data.a, data.b);
	__ss(&data);
	//printf("4\n");
	//printf("======\n");
	print_list(data.a, data.b);
	__rr(&data);
	//printf("======\n");
	print_list(data.a, data.b);
	__size_stack_ab(&data);
	//printf(" stack_a = %d\n stack_b = %d\n",data.size_a, data.size_b);
	//printf("======\n");
	print_list(data.a, data.b);
	__rra(&data);
	//printf("======\n");
	print_list(data.a, data.b);
	__rrr(&data);
	//printf("======\n");
	print_list(data.a, data.b);
	*/
}