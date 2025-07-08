/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 12:18:51 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 12:18:51 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// erases the data in the n bytes of the memory
// writing zeros to the area, where pointing s
void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
