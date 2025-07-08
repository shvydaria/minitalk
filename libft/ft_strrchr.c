/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:28:01 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:28:01 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// finds the last occurrence of the character c in the string s
char	*ft_strrchr(const char *str, int chr)
{
	char	ch;
	char	*last;

	last = NULL;
	ch = (char)chr;
	while (*str)
	{
		if (*str == ch)
		{
			last = (char *)str;
		}
		str++;
	}
	if (*str == ch)
	{
		return ((char *)str);
	}
	return (last);
}
