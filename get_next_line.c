/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:51 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/15 01:43:29 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_save(char *save, char *buf, char *line)
{
	char	*src;
	char	*tmp;

	src = NULL;
	if (save == NULL)
	{
		src = ft_strdup("\0");
		if (src == NULL)
			return (NULL);
		return (src);
	}
	tmp = ft_strdup(save);
	if (tmp == NULL)
		return (NULL);
	free(save);
	if (line == NULL)
		src = ft_strjoin(tmp, buf);
	else if (ft_strchr(buf, '\n'))
		src = ft_strdup(ft_strchr(buf, '\n') + 1);
	else if (ft_strchr(tmp, '\n'))
		src = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	if (src == NULL)
		return (NULL);
	return (src);
}

static char	*ft_get_line(char *save, ssize_t *n)
{
	size_t	i;
	char	*line;

	i = 0;
	if (ft_strchr(save, '\n'))
		while (save[i] != '\n')
			i++;
	else
		i = ft_strlen(save);
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, i + 1);
	if (ft_strchr(save, '\n'))
		line[i] = '\n';
	line[i + 1] = '\0';
	if (*n == 0 && ft_strchr(save, '\n') == NULL)
		*n = -1;
	return (line);
}

static char	*ft_get_end(char *save, char *line, char *buf, ssize_t n)
{
	if (n == -1)
	{
		free(save);
		save = ft_strdup("\0");
		if (save == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	if (n == -1 && line != NULL)
		free(save);
	else if (line == NULL)
		free(save);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	char		*line;
	ssize_t		n;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	n = 0;
	line = NULL;
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + (size_t)1));
	if (save[fd] == NULL)
		save[fd] = ft_get_save(save[fd], NULL, NULL);
	while (save[fd] != NULL && buf != NULL && line == NULL)
	{
		if (ft_strchr(save[fd], '\n') == NULL)
			n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		if (ft_strchr(save[fd], '\n') || \
			(n == 0 && *save[fd] != '\0' && line == NULL))
			line = ft_get_line(save[fd], &n);
		save[fd] = ft_get_save(save[fd], buf, line);
		if (n == -1 || n == 0)
			break ;
	}
	return (ft_get_end(save[fd], line, buf, n));
}
