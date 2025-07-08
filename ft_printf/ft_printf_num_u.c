/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:48:39 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:48:39 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// % u Prints an unsigned decimal(base 10) number.
static int	get_num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long num, int len)
{
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*result;
	unsigned int	temp;

	if (n == 0)
		return (ft_strdup("0"));
	temp = n;
	len = get_num_len(temp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	fill_str(result, n, len);
	return (result);
}

int	ft_printf_num_u(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_utoa(num);
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
