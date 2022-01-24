/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_OK.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngiroux <ngiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:15:37 by ngiroux           #+#    #+#             */
/*   Updated: 2022/01/09 15:20:42 by ngiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	__empty(void)
{
	char buffer[BUFFER_SIZE];
	int file;

	bzero((void *)buffer, BUFFER_SIZE);
	system("cd ..");
	system("./push_swap > res.txt");
	file = open("res.txt", O_RDONLY, 0777);
	read(file, buffer, BUFFER_SIZE);
	if (strcmp(buffer,"") != 0)
	{
		__log_test("./push_swap ", "", buffer);
		return (-1);
	}
	else
	{
		system("valgrind --log-file=\"leak\" ./push_swap > res.txt");
		file = open("leak", O_RDONLY, 0777);
		if (__leaks(file) == 0)
			return (0);
		else 
			return (69);
	}	
}
