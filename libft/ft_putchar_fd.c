/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:22:20 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:22:20 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// same as putchar, but we're choosing file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
