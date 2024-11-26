/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:40:46 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/12 17:13:16 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	i = 0;
	t1 = (unsigned char *)dst;
	t2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (t1 > t2)
	{
		while (len-- > 0)
			t1[len] = t2[len];
	}
	else
	{
		while (i < len)
		{
			t1[i] = t2[i];
			i++;
		}
	}
	return (dst);
}
