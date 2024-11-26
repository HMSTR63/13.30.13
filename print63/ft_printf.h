/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:47:02 by sojammal          #+#    #+#             */
/*   Updated: 2024/11/25 15:04:53 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putptr(size_t ptr);
int	ft_puthex(unsigned int nbr, char format);
int	ft_putunbr(unsigned int nbr);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putchar(char c);
int	ft_printf(const char *format, ...);

#endif