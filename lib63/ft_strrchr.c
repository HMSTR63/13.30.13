/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:14:15 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:41 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			u_c;
	char			*result;

	i = 0;
	u_c = (char)c;
	result = NULL;
	while (s[i])
	{
		if (s[i] == u_c)
			result = (char *)&s[i];
		i++;
	}
	if (s[i] == u_c)
		result = (char *)&s[i];
	return (result);
}
