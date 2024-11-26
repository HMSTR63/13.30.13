/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:14:50 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/25 15:07:47 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	unsigned int	n;
	char			c;

	n = 0;
	if (nbr > 9)
	{
		n += ft_putunbr(nbr / 10);
		n += ft_putunbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		n += write(1, &c, 1);
	}
	return (n);
}
