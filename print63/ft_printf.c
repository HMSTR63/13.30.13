/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:18:52 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/25 23:20:04 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	int	size;

	size = 0;
	if (c == '%')
		size = ft_putchar('%');
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		size += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		size += ft_putptr((size_t)va_arg(args, void *));
	else if (c == 'u')
		size += ft_putunbr(va_arg(args, unsigned int));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	if (write(1, "", 0) == -1)
		return (-1);
	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\n')
				size += ft_putchar('\n');
			else if (format[i])
				size += ft_format(args, format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
