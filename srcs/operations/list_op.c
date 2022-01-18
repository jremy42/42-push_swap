/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:29:14 by jremy             #+#    #+#             */
/*   Updated: 2022/01/18 12:41:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*__cmdnew(int cmd)
{
	t_cmd	*newlst;

	newlst = malloc(sizeof(t_cmd));
	if (!newlst)
		return (NULL);
	newlst->cmd = cmd;
	newlst->next = NULL;
	return (newlst);
}

void	__cmdadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*nextlst;

	if (!(*alst))
		*alst = new;
	else
	{
		nextlst = (*alst);
		while (nextlst->next)
			nextlst = nextlst->next;
		nextlst->next = new;
	}
}

int	__insert_cmd(t_data *data, int op)
{
	t_cmd	*new;

	new = __cmdnew(op);
	if (!new)
		return (-1);
	__cmdadd_back(&data->cmd, new);
	return (0);
}

void	print_cmd(int cmd)
{
	if (cmd == PA)
		__putstr_fd("pa\n", 1);
	if (cmd == PB)
		__putstr_fd("pb\n", 1);
	if (cmd == RRA)
		__putstr_fd("rra\n", 1);
	if (cmd == RRB)
		__putstr_fd("rrb\n", 1);
	if (cmd == RA)
		__putstr_fd("ra\n", 1);
	if (cmd == RB)
		__putstr_fd("rb\n", 1);
	if (cmd == SA)
		__putstr_fd("sa\n", 1);
	if (cmd == SB)
		__putstr_fd("sb\n", 1);
	if (cmd == RRR)
		__putstr_fd("rrr\n", 1);
	if (cmd == RR)
		__putstr_fd("rr\n", 1);
	if (cmd == SS)
		__putstr_fd("ss\n", 1);
}

int __size_cmd(t_cmd *cmd)
{
	t_cmd *tmp;
	int len;

	tmp = cmd;
	len = 0;
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	print_cmd_lst(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	tmp = cmd;
	if (__size_cmd(cmd) > 50)
	{
		while (tmp->next != NULL)
		{
			if (tmp->cmd == RA && tmp->next->cmd == RB
				&& tmp->next->next != NULL)
			{
				print_cmd(RR);
				tmp = tmp->next->next;
			}
			if (tmp->cmd == RRB && tmp->next->cmd == RRA
				&& tmp->next->next != NULL)
			{
				print_cmd(RRR);
				tmp = tmp->next->next;
			}
			else
			{
				print_cmd(tmp->cmd);
				tmp = tmp->next;
			}
		}
	}
	while (tmp != NULL)
	{
		print_cmd(tmp->cmd);
		tmp = tmp->next;
	}
}