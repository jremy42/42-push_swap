/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:53:26 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 12:06:18 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check_overflow(long long result)
{
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (0);
}

static int	ft_in_stack(int save, t_data *data)
{
	t_stack	*tmp;

	if (is_present(save, data->a) == -1)
		return (-1);
	tmp = ft_stacknew(&save);
	if (!tmp)
		return (-1);
	ft_stackadd_back(&data->a, tmp);
	return (0);
}

static int	ft_check_digit(const char *nb)
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
		if (ft_isdigit(nb[i]) != 1)
			return (-1);
		i++;
	}
	if (i == check)
		return (-1);
	return (0);
}

int	ft_atol(const char *nb, t_data *data)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_check_digit(nb) == -1)
		return (-1);
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nb[i]) && nb[i])
	{
		result = result * 10 + (nb[i] - '0');
		if (ft_check_overflow(result * sign) == -1)
			return (-1);
		i++;
	}
	if (ft_in_stack((int)result * sign, data) == -1)
		return (-1);
	return (0);
}
