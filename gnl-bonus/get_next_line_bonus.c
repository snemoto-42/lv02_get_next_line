/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:51 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/08 17:10:17 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (ft_strchr(save, '\n'))
		while (save[i] != '\n')
			i++;
	else
		i = ft_strlen(save);
	line = (char *) malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, i + 1);
	if (ft_strchr(save, '\n'))
		ft_strlcat(line, "\n", ft_strlen(line) + ft_strlen("\n") + 1);
	*save = '\0';
	return (line);
}

static char	*ft_find_newline(char *buf, char *save, ssize_t len_buf)
{
	size_t	len_save;
	char	*tmp_save;
	char	*tmp_buf;
	char	*line;

	line = NULL;
	tmp_buf = ft_strchr(buf, '\n');
	len_save = ft_strlen(save);
	tmp_save = ft_strchr(save, '\n');
	if (tmp_buf || tmp_save)
	{
		ft_strlcat(save, buf, len_save + len_buf + 1);
		line = ft_get_line(save);
		if (tmp_buf)
			ft_strlcpy(save, tmp_buf + 1, len_buf);
		else
			ft_strlcpy(save, tmp_save + 1, len_save);
	}
	else
		ft_strlcat(save, buf, len_save + len_buf + 1);
	return (line);
}

char	*ft_make_buf(int fd)
{
	char	*buf;

	if (fd < 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	save[256][BUFFER_SIZE];
	char		*buf;
	char		*line;
	ssize_t		n;

	buf = ft_make_buf(fd);
	line = NULL;
	while (buf != NULL && line == NULL)
	{
		n = 0;
		if (ft_strchr(save[fd], '\n') == NULL)
		{
			n = read(fd, buf, BUFFER_SIZE);
			if (n == -1 || n == 0)
			{
				if (save[fd][0] != '\0')
					line = ft_get_line(save[fd]);
				break ;
			}
		}
		buf[n] = '\0';
		line = ft_find_newline(buf, save[fd], n);
	}
	free(buf);
	return (line);
}
