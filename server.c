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

// Collects incoming bits into a byte
// Prints the character when all 8 bits are received
// it’s more efficient to pass a pointer than copy everything because of amount of data
// signum – Which signal (e.g. SIGUSR1)
// info – Pointer to signal info (like who sent it)
// SIGUSR1 and SIGUSR2 are free signals for users ("USR" = user)
// SIGUSR1 = binary 1 SIGUSR2 = binary 0

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)context;

	if (signum == SIGUSR1)
		c |= (1 << bit); // Set the bit for SIGUSR1
	bit++;
	if (bit == 8) // Completed a byte
	{
        if (c == '\0') {
			ft_printf("\nEnd of message received.\n");
			kill(info->si_pid, SIGUSR1);
		}
        else
			write(1, &c, 1); // Print the received character
		bit = 0;
		c = 0; // Reset for the next byte
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
	sigaction(SIGUSR1, &sa, NULL); // Don't block other signals while handling.
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
