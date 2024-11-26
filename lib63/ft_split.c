/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:30:39 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/12 23:46:23 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_w(const char *s, char c)
{
	size_t	count;
	size_t	is_w;
	size_t	i;

	count = 0;
	is_w = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_w = 1;
		else if (is_w == 1)
		{
			count++;
			is_w = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	**ft_stor_list(char **list, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	s_size;
	size_t	x;

	i = 0;
	x = 0;
	s_size = ft_strlen(s);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (j < i)
		{
			list[x] = ft_substr(s, j, i - j);
			if (list[x] == NULL)
				return (ft_free_list(list), NULL);
			x++;
		}
	}
	list[x] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	new_word;

	if (s == NULL)
		return (NULL);
	new_word = ft_count_w(s, c);
	list = malloc((new_word + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	list = ft_stor_list(list, s, c);
	return (list);
}
