/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:52:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/10 16:10:38 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__exit(char**str, t_data *data)
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
	(void)data;
	//printf("Error \n");
	exit(0);
}

int	__check(char **str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
			////printf("=> %d\n",i);
		if (__atol(str[i], data) == -1)
			return (-1);
		i++;
	}
	return (0);
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
	i = 0;
	if (__check(&split_tmp[i], data) == -1)
		__exit(split_tmp, data);
}
