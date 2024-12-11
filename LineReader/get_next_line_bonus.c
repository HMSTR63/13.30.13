/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:21:48 by sojammal          #+#    #+#             */
/*   Updated: 2024/12/11 00:55:08 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *read_from_fd(int fd, char *buffer)
{
	char    *tmp_holder;
	char    *new_holder;
	int     reading_bytes;

	reading_bytes = 1;
	tmp_holder = malloc(BUFFER_SIZE + 1);
	if (!tmp_holder)
		return (free(tmp_holder), NULL);
	while(1)
	{
		reading_bytes = read(fd, tmp_holder, BUFFER_SIZE);
		if (reading_bytes < 0)
			return (free(buffer), free(tmp_holder), NULL);
		if (reading_bytes == 0)
			break;
		tmp_holder[reading_bytes] = '\0';
		new_holder = ft_strjoin(buffer, tmp_holder);
		buffer = new_holder;
		if (ft_strchr(tmp_holder, '\n'))
			break;
	}
	return (free(tmp_holder), buffer);
}
char *extract_line(char *buffer)
{
	char    *line;
	char    *newline;
	int     line_len;
	int     i;
	
	i = 0;
	newline = ft_strchr(buffer, '\n');
	if (newline)
		line_len = newline - buffer + 1;
	else
		line_len = ft_strlen(buffer);
	line = malloc(line_len + 1);
	if (!line)
		return (free(line), NULL);
	while (i < line_len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[line_len] = '\0';
	return (line);
}
char *clean_up_buffer(char *buffer)
{
	char    *newline;
	char    *remaining_buffer;
	int     remaining_len;
	int     i;

	newline = ft_strchr(buffer, '\n');
	if (newline)
	{
		remaining_len = ft_strlen(newline + 1);
		remaining_buffer = malloc(remaining_len + 1);
		if (!remaining_buffer)
			return (free(buffer), free(remaining_buffer), NULL);
		i = 0;
		while (newline[i + 1])
		{
			remaining_buffer[i] = newline[i + 1];
			i++;
		}
		remaining_buffer[i] = '\0';
	}
	else
		remaining_buffer = NULL;
	free(buffer);
	return (remaining_buffer);
}
char    *get_next_line(int fd)
{
	static char *buffer[OPEN_MAX];
	char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	 if (read(fd, 0, 0) < 0)
		return (free(buffer[fd]), NULL);
	buffer[fd] = read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = clean_up_buffer(buffer[fd]);
	return (line);
}
