/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngiroux <ngiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:04:29 by ngiroux           #+#    #+#             */
/*   Updated: 2022/01/09 15:31:34 by ngiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	ft01_launcher(t_score *score)
{
	t_utest	*testlist;
	int		res;

	res = 0;
	testlist = NULL;
	__loader(&testlist, "CHECKER", "int_min", &__int_min_c);
	__loader(&testlist, "CHECKER", "int_max", &__int_max_c);
	__loader(&testlist, "CHECKER", "doublons", &__doublons_c);
	__loader(&testlist, "CHECKER", "input1", &__input1);
	__loader(&testlist, "CHECKER", "input2", &__input2);
	__loader(&testlist, "CHECKER", "input3", &__input3);
	__loader(&testlist, "CHECKER", "input4", &__input4);
	__loader(&testlist, "CHECKER", "char", &__char_c);
	__loader(&testlist, "CHECKER", "empty", &__empty_c);
	__loader(&testlist, "CHECKER", "empty2", &__empty2_c);
	__loader(&testlist, "CHECKER", "empty3", &__empty3_c);		
	__launcher(testlist, score);
	return (res);
}
