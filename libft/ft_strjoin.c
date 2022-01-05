/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:06:59 by jremy             #+#    #+#             */
/*   Updated: 2021/11/24 17:11:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, const char *src)
{
	ft_strcpy(dst + ft_strlen(dst), src);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	result = ft_strcpy(result, s1);
	result = ft_strcat(result, s2);
	return (result);
}
