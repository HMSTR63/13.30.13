/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:22:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/01 20:20:24 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid, char h, int bit)
{
	if ((h & (1 << bit)) != 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("\e[033;0;31m→  Invalid PID. Signal sending failed. \e[0m\n", 2);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("\e[033;0;31m→  Invalid PID. Signal sending failed. \e[0m\n", 2);
			exit(1);
		}
	}
	usleep(500);
}
void	ft_send_char(int pid, char h)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		ft_send_bit(pid, h, bit);
		bit++;
	}
}
void	ft_send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_send_char(pid, msg[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}
int	validate_pid(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
		{
			ft_putstr_fd("\e[033;0;31m→  PID contains non-digit characters. \e[0m\n", 2);
			return (0);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		ft_putstr_fd("\e[033;0;31m→  PID must be a positive integer. \e[0m\n", 2);
		return (0);
	}
	return (pid);
}
int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3 && av[2][0] != '\0')
	{
		pid = validate_pid(av[1]);
		if (pid != 0)
		{
			ft_putstr_fd("\e[033;0;32m→  Valid PID. Starting message transmission. \e[0m\n", 1);
			ft_send_message(pid, av[2]);
		}
	}
	else
	{
		ft_putstr_fd("\e[033;0;31m→  Incorrect number of arguments or empty message. \e[0m\n", 2);
		ft_putstr_fd("\e[033;0;35m→  Usage: ./client [PID] [MESSAGE] \e[0m\n", 2);
	}
}
