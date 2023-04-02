/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:53 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/07 00:47:19 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	else if (dstsize <= src_size)
		size = dstsize - 1;
	else
		size = src_size;
	while (size-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n_dst;
	size_t	n_src;

	n_src = ft_strlen(src);
	if (dstsize == 0)
		return (n_src);
	n_dst = ft_strlen(dst);
	if (dstsize <= n_dst)
		return (n_src + dstsize);
	ft_strlcpy(dst + n_dst, src, dstsize - n_dst);
	return (n_src + n_dst);
}
