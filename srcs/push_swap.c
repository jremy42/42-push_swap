/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/14 10:59:02 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	int test;

	test = 0;
	if (ac < 1)
	{
		__putstr_fd("Error\n Needs input",0);
	}
	__parsing(av, &data);
	//__index(&data);
	//test = __next_pivot(data.a);
	//printf("next pivot = %d\n",test);
	//print_stack(data.a);
	__algo4(&data);
}