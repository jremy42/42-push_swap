/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:01:17 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 14:30:06 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__convert(char *str)
{
	if (__strncmp(str, "pa\n", 5) == 0)
		return (PA);
	if (__strncmp(str, "pb\n", 5) == 0)
		return (PB);
	if (__strncmp(str, "rra\n", 5) == 0)
		return (RRA);
	if (__strncmp(str, "rrb\n", 5) == 0)
		return (RRB);
	if (__strncmp(str, "ra\n", 5) == 0)
		return (RA);
	if (__strncmp(str, "rb\n", 5) == 0)
		return (RB);
	if (__strncmp(str, "sa\n", 5) == 0)
		return (SA);
	if (__strncmp(str, "sb\n", 5) == 0)
		return (SB);
	if (__strncmp(str, "rrr\n", 5) == 0)
		return (RRR);
	if (__strncmp(str, "rr\n", 5) == 0)
		return (RR);
	if (__strncmp(str, "ss\n", 5) == 0)
		return (SS);
	else
		return (-1);
}

int	__read_input(t_data *data)
{
	char	*read;	
	int		i;

	i = 0;
	while (1)
	{
		read = get_next_line(0);
		if (read == NULL)
			break;
		if (__convert(read) == -1)
		{
			get_next_line(-1);
			__error("Error\n", data);
		}
		else
		{
			if (__insert_cmd(data, __convert(read)))
			{
				get_next_line(-1);
				__error("Malloc Error\n", data);
			}
			free(read);
		}
		i++;
	}
	return (0);
}

int __do_instruct(t_data *data)
{
	t_cmd	*tmp;

	__index(data);
	tmp = __copy_cmd(data->cmd);
	while (tmp != NULL)
	{
		__op_bf(data, tmp->cmd);
		//print_list(data->a, data->b);
		tmp = tmp->next;
	}
	if (__sort_bf(data) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		__putstr_fd("Error\n Needs input", 0);
	__parsing(av, &data);
	__read_input(&data);
	if (__do_instruct(&data) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	//print_list(data.a, data.b);
	//print_cmd_lst(data.cmd);
}
