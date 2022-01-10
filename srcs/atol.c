/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:53:26 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 14:58:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	__check_overflow(long long result)
{
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (0);
}

static int	__in_stack(int save, t_data *data)
{
	t_stack	*tmp;

	if (is_present(save, data->a) == -1)
		return (-1);
	tmp = __stacknew(&save);
	if (!tmp)
		return (-1);
	__stackadd_back(&data->a, tmp);
	return (0);
}

static int	__check_digit(const char *nb)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (nb[i] == '-' || nb[i] == '+')
	{
		i++;
		check++;
	}
	while (nb[i])
	{
		if (__isdigit(nb[i]) != 1)
			return (-1);
		i++;
	}
	if (i == check)
		return (-1);
	return (0);
}

int	__atol(const char *nb, t_data *data)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (__check_digit(nb) == -1)
		return (-1);
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign = -1;
		i++;
	}
	while (__isdigit(nb[i]) && nb[i])
	{
		result = result * 10 + (nb[i] - '0');
		if (__check_overflow(result * sign) == -1)
			return (-1);
		i++;
	}
	if (__in_stack((int)result * sign, data) == -1)
		return (-1);
	return (0);
}
