/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:34:23 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/20 12:38:18 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
	size_t	total;

	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	alloc = malloc(total);
	if (!alloc)
		return (NULL);
	return (ft_memset(alloc, 0, total));
}
