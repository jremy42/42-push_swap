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

int	__int_min(void);
int	__int_max(void);
int	__test_ok(void);
int	__test_ko(void);
int	__test_sigsev(void);
int	__test_bus(void);
int	ft_strlen(char *str);

#endif
