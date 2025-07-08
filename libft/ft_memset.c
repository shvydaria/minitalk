/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 13:21:54 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 13:21:54 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// set a block of mem to a spec value
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned long	i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main() {
//     char buffer[10];
//     ft_memset(buffer, 65, sizeof(buffer));
//     for (int i = 0; i < sizeof(buffer); i++) {
//         printf("%c ", buffer[i]);
//     }

//     return (0);
// }