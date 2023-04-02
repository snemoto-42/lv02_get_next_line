/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:37:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/15 01:42:32 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i++], O_RDONLY);
		while ((str = get_next_line(fd)) != NULL)
		{
			printf("%s", str);
			free(str);
		}	
		// close(fd);
		// str = get_next_line(fd);
		// // printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
	}
	// free(str);
	// system("leaks gnl");
	close(fd);
	return (0);
}
