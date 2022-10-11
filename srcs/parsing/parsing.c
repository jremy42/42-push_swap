/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:52:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/19 09:17:52 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__exit(char**str, t_data *data, int error)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	if (error == 1)
		write(2, "Error\n", 6);
	__exit_ps(data, error);
}

int	__check(char **str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (__atol(str[i], data) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static void	__free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	__parsing(char **input, t_data *data)
{
	int		i;
	char	*tmp;
	char	**split_tmp;

	i = 1;
	tmp = __strdup(" ");
	while (input[i])
	{
		tmp = __strjoin(tmp, input[i]);
		tmp = __strjoin(tmp, " ");
		i++;
	}
	split_tmp = __split(tmp, ' ');
	free(tmp);
	if (!split_tmp[0])
		__exit(split_tmp, data, 1);
	i = 0;
	if (__check(&split_tmp[i], data) == -1)
		__exit(split_tmp, data, 1);
	if (data->a == NULL)
		__exit(split_tmp, data, 1);
	__free_split(split_tmp);
}
