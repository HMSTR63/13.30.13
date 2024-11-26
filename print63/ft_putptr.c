/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:19:15 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/25 22:49:43 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(size_t nbr)
{
	const char	*base;
	char		hexchar;
	int			hexcount;

	base = "0123456789abcdef";
	hexcount = 0;
	if (nbr >= 16)
	{
		hexcount += ft_printhex(nbr / 16);
		hexcount += ft_printhex(nbr % 16);
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

int	ft_putptr(size_t ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_printhex(ptr);
	return (count);
}
