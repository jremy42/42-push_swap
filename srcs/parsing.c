/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:52:38 by jremy             #+#    #+#             */
/*   Updated: 2022/01/06 18:54:43 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char**str, t_data *data)
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
	printf("Error \n");
	exit(0);
}

int	ft_check(char **str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
			//printf("=> %d\n",i);
		if (ft_atol(str[i], data) == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_parsing(char **input, t_data *data)
{
	int		i;
	char	*tmp;
	char	**split_tmp;

	i = 1;
	tmp = ft_strdup(" ");
	while (input[i])
	{
		tmp = ft_strjoin(tmp, input[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	split_tmp = ft_split(tmp, ' ');
	free(tmp);
	i = 0;
	if (ft_check(&split_tmp[i], data) == -1)
		ft_exit(split_tmp, data);
}
