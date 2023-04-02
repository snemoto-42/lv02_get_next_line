/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:53 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/13 21:10:56 by snemoto          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*rv;

	size = ft_strlen(s1);
	rv = (char *) malloc(sizeof(char) * (size + 1));
	if (rv == NULL)
		return (NULL);
	ft_strlcpy(rv, s1, size + 1);
	return (rv);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*rv;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	rv = (char *) malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (rv == NULL)
		return (NULL);
	ft_strlcpy(rv, s1, size_s1 + 1);
	ft_strlcpy(rv + size_s1, s2, size_s2 + 1);
	return (rv);
}
