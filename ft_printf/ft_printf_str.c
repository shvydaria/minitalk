/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:48:36 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:48:36 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// %s Prints a string (as defined by the common C convention).

int	ft_putstr(char *str)
{
	int	i;
	int	check;

	i = 0;
	while (str[i] != '\0')
	{
		check = write(1, &str[i], 1);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}
