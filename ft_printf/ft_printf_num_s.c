/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:47:58 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:47:58 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// % d Prints a decimal(base 10) number.
// % i Prints an integer in base 10.

int	ft_printf_num_s(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
