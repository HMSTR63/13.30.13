/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:20:07 by sojammal          #+#    #+#             */
/*   Updated: 2024/12/09 11:08:23 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*list;
	size_t	p1;
	size_t	p2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	p1 = ft_strlen(s1);
	p2 = ft_strlen(s2);
	list = malloc(p1 + p2 + 1);
	if (!list)
		return (NULL);
	ft_strlcpy(list, s1, p1 + 1);
	ft_strlcat(list, s2, p1 + p2 + 1);
	return (list);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	i;

	srcl = ft_strlen(src);
	i = 0;
	if (dstsize > 0 && src)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcl);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src != dst)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;

	srcl = ft_strlen(src);
	if (dstsize == 0)
		return (srcl);
	dstl = ft_strlen(dst);
	if (dstl >= dstsize)
		return (dstsize + srcl);
	if (srcl < dstsize - dstl)
		ft_memcpy(dst + dstl, src, srcl + 1);
	else
	{
		ft_memcpy(dst + dstl, src, dstsize - dstl - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstl + srcl);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_l;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	i = 0;
	if (start >= s_l)
		return (ft_strdup(""));
	if (len > (s_l - start))
		len = s_l - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + 1];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
