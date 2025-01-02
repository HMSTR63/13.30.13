/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:51:07 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/02 01:26:44 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static unsigned char	h;
	static int	            pid;
	static int	            p_bit;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		p_bit = 0;
		h = 0;
	}
	if (sig == SIGUSR1)
		h |= (1 << p_bit);
	p_bit++;
	if (p_bit == 8)
	{
        if (h == 255)
            kill(info->si_pid, SIGUSR1);
        else
		    ft_putchar_fd(h, 1);
		h = 0;
		p_bit = 0;
	}
}
int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_putstr_fd("\e[036;1mServer PID: \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\e[032;1mWaiting for message...\e[0m\n", 1);
	sig.sa_sigaction = ft_btoa;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
