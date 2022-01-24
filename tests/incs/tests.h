/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngiroux <ngiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:31:19 by ngiroux           #+#    #+#             */
/*   Updated: 2022/01/09 15:26:17 by ngiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdlib.h>
# include <libunit.h>

int	ft00_launcher(t_score *score);
int	ft01_launcher(t_score *score);

int	__int_min(void);
int	__int_max(void);
int	__doublons(void);
int	__sort1(void);
int	__sort2(void);
int	__sort3(void);
int	__char(void);
int	__empty(void);
int	__empty2(void);
int	__empty3(void);
int	ft_strlen(char *str);

int	__int_min_c(void);
int	__int_max_c(void);
int	__doublons_c(void);
int	__input1(void);
int	__input2(void);
int	__input3(void);
int	__input4(void);
int	__char_c(void);
int	__empty_c(void);
int	__empty2_c(void);
int	__empty3_c(void);

#endif
