/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:26 by jremy             #+#    #+#             */
/*   Updated: 2021/11/29 08:36:07 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str, char tofind);
int		ft_strlen(char *str);
char	*ft_strjoingnl(char *dest, char *src);
char	*ft_get_line(char *str);
int		ft_size_line(char *str);
char	*ft_save_memory(char *str);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_read_file(int fd, char *memory);
#endif
