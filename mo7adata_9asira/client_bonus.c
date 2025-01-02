/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:59:16 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/02 01:53:44 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("Message succesfully sent to the server\n", 1);
	exit(0);
}
void	ft_send_signal(int pid, char h)
{
	int signal;
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (h & (1 << bit))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_putstr_fd("\e[033;0;31m→  Invalid PID. Signal sending failed. \e[0m\n", 2);
			exit(1);
		}
		usleep(500);
		bit++;
	}
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
	int	i;

	i = 0;
	if (ac == 3 && av[2][0] != '\0')
	{
		pid = validate_pid(av[1]);
		if (pid != 0)
		{
			signal(SIGUSR1, ft_success);
			while (av[2][i])
			{
				ft_send_signal(pid, av[2][i++]);
			}
			ft_send_signal(pid, '\0');
			while (1)
				pause();
		}
	}
	else
	{
		ft_putstr_fd("\e[033;0;31m→  Incorrect number of arguments or empty message. \e[0m\n", 2);
		ft_putstr_fd("\e[033;0;35m→  Usage: ./client [PID] [MESSAGE] \e[0m\n", 2);
	}
	return (0);
}
