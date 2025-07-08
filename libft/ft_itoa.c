/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:25:03 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:25:03 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocates with malloc and returns a string representing the integer
// iterate through tab, spaces, etc. 9-13||32
// handle minus counter; convert digits(chars) to integers
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

char	*ft_itoa(int n)
{
	int		len;
	int		is_minus;
	long	num;
	char	*result;
	long	temp;

	len = 0;
	is_minus = 0;
	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		is_minus = 1;
		num = -num;
	}
	temp = num;
	len = get_num_len(temp) + is_minus;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (is_minus)
		result[0] = '-';
	fill_str(result + is_minus, num, len - is_minus);
	return (result);
}
