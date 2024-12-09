/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:32:11 by sojammal          #+#    #+#             */
/*   Updated: 2024/12/09 11:02:32 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_from_fd(int fd, char *buffer)
{
    char    tmp_holder[BUFFER_SIZE + 1];
    char    *new_holder;
    int     reading_bytes;

    while(1)
    {
        reading_bytes = read(fd, tmp_holder, BUFFER_SIZE);
        if (reading_bytes < 0)
            return (free(buffer), buffer = NULL, NULL);
        if (reading_bytes == 0)
            break;
        tmp_holder[reading_bytes] = '\0';
        new_holder = ft_strjoin(buffer, tmp_holder);
        free(buffer);
        buffer = new_holder;
        if (ft_strchr(tmp_holder, '\n'))
            break;
    }
    return (buffer);
}
static char *extract_line(char *buffer)
{
    char    *line;
    char    *newline;

    newline = ft_strchr(buffer, '\n');
    if (newline)
        line = ft_substr(buffer, 0, newline - buffer + 1);
    else
        line = ft_substr(buffer, 0, ft_strlen(buffer));
    return (line);
}
static char *clean_up_buffer(char *buffer)
{
    char    *newline;
    char    *remaining_buffer;

    newline = ft_strchr(buffer, '\n');
    if (newline)
        remaining_buffer = ft_substr(newline + 1, 0, ft_strlen(newline + 1));
    else
        remaining_buffer = NULL;
    free(buffer);
    return (remaining_buffer);
}
char	*get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (free(buffer), buffer = NULL, NULL);
    buffer = read_from_fd(fd, buffer);
    if (!buffer)
        return (NULL);
    line = extract_line(buffer);
    buffer = clean_up_buffer(buffer);
    return (line);
}
