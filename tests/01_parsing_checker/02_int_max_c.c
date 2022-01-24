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

int	__int_max_c(void)
{
	char buffer[BUFFER_SIZE];
	int file;

	bzero((void *)buffer, BUFFER_SIZE);
	system("cd ..");
	system("./checker 2147483649 2> res.txt");
	file = open("res.txt", O_RDONLY, 0777);
	read(file, buffer, BUFFER_SIZE);
	if (strcmp(buffer,"Error\n") != 0)
	{
		__log_test("./checker 2147483649", "Error\n", buffer);
		return (-1);
	}
	else
	{
		system("valgrind --log-file=\"leak\" ./checker 2147483649 2> res.txt");
		file = open("leak", O_RDONLY, 0777);
		if (__leaks(file) == 0)
			return (0);
		else 
			return (69);
	}
}
