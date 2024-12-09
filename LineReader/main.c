/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:14:39 by aperez-b          #+#    #+#             */
/*   Updated: 2024/12/09 21:10:44 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int	main(void)
{
	int		fd_1;
	int		i;
	char	*line[FOPEN_MAX];

	i = 1;
	fd_1 = open("test.txt", O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		if (!line[fd_1])
			return (0);
		free(line[fd_1]);
		i++;
	}
}
