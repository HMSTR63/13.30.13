/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:21:48 by sojammal          #+#    #+#             */
/*   Updated: 2024/12/12 00:20:45 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	lm(char *line, int i)
{
	if (line[i] == '\n')
		return (1);
	return (0);
}

char	*read_from_fd(int fd, char *buffer)
{
	char	*tmp_holder;
	int		reading_bytes;

	tmp_holder = malloc(BUFFER_SIZE + 1);
	if (!tmp_holder)
		return (NULL);
	reading_bytes = 1;
	while (!ft_strchr(buffer, '\n') && reading_bytes > 0)
	{
		reading_bytes = read(fd, tmp_holder, BUFFER_SIZE);
		if (reading_bytes == -1)
			return (free(buffer), free(tmp_holder), NULL);
		tmp_holder[reading_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_holder);
	}
	return (free(tmp_holder), buffer);
}

char	*extract_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	i = len_at_newline(line, 0);
	str = malloc (i + 1 + lm(line, i));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*clean_up_buffer(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	i = len_at_newline(line, 0);
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer[fd] = read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = clean_up_buffer(buffer[fd]);
	return (line);
}
