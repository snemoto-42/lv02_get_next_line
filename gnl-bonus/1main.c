/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:37:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/08 17:08:03 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "get_next_line_bonus.h"
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
		// printf("%s\n", get_next_line(42));
		str = NULL;
		while ((str = get_next_line(fd)) != NULL)
			printf("%s", str);
	}
	// printf("----------\n");
	// system("leaks gnl");
	// printf("----------\n");
	close(fd);
	return (0);
}
