/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:24:23 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:24:23 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// not dumb, but dup -> duplicates the string, allocates mem for new str
char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s1);
	dest = malloc(s_len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s_len + 1);
	return (dest);
}
