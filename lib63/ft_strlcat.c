/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:40:24 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/12 23:54:59 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
