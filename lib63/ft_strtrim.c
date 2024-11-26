/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:13:00 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/12 23:54:45 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	p1;
	size_t	p20;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	p1 = 0;
	p20 = ft_strlen(s1);
	while (p1 < p20 && ft_strchr(set, s1[p1]))
		p1++;
	while (p20 > p1 && ft_strchr(set, s1[p20 - 1]))
		p20--;
	return (ft_substr(s1, p1, p20 - p1));
}
