/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 12:30:11 by dashvydk          #+#    #+#             */
/*   Updated: 2025-06-05 12:30:11 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("\nEnd of message received.\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
