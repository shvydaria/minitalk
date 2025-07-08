/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:27:49 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:27:49 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locates the fist occurrence of the \0 needle in the haystack
char	*ft_strnstr(char *haystack, char *needle, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] != '\0' && i < size)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < size
			&& needle[j] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return (haystack + i);
		i++;
	}
	return (NULL);
}
