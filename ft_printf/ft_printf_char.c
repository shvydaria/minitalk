/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:47:35 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:47:35 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// %c Prints a single character.
// %% Prints a percent sign.
int	ft_printf_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
