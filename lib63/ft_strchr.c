/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:16:21 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/11 23:27:34 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	u_c;

	i = 0;
	u_c = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == u_c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == u_c)
		return ((char *)&s[i]);
	return (NULL);
}
