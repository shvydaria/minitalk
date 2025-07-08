/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 12:30:01 by dashvydk          #+#    #+#             */
/*   Updated: 2025-06-05 12:30:01 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Character received successfully.\n");
	else
		ft_printf("Error receiving character.\n");
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID.\n");
		return (1);
	}
	str = argv[2];
	if (!str || ft_strlen(str) == 0)
	{
		ft_printf("Error: Message cannot be empty.\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
	pause();
	return (0);
}
