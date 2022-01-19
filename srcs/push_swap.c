/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 14:30:17 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	data.cmd = NULL;
	if (ac == 1)
	{
		__putstr_fd("Error\n", 0);
		return (1);
	}
	__parsing(av, &data);
	__algo4(&data);
	return (0);
}
