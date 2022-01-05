/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 12:50:46 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	ft_parsing(av, &data);
	print_list(data.a);
	data.a = ft_swap_a(data.a);
	printf("======\n");
	print_list(data.a);
	data.a = ft_swap_a(data.a);
	printf("======\n");
	print_list(data.a);

}