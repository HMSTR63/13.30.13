/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:14:09 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/25 15:06:33 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char format)
{
	const char	*base;
	char		hexchar;
	int			hexcount;

	hexcount = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		hexcount += ft_puthex(nbr / 16, format);
		hexcount += ft_puthex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			hexchar = nbr + '0';
		else
			hexchar = base[nbr];
		hexcount += write(1, &hexchar, 1);
	}
	return (hexcount);
}
