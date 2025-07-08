/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:28:18 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:28:18 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// specified in set removed from the beginning and the end of the string
// using strchr check for similarities from end and from start.
// allocates memory (end - start + 2)
// +2 cause of strlcpy for enough space for the trimmed string and '\0'
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	result = (char *)malloc(end - start + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], end - start + 2);
	return (result);
}
