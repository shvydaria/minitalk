/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:51:01 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:51:01 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printf_char(char c);
int		ft_printf_percent(void);
int		ft_printf_str(char *str);
int		ft_printf_num_s(int num);
int		ft_printf_num_u(unsigned int num);
int		ft_printf_hex(unsigned int num, int is_uppercase);
int		ft_printf_pointer(void *ptr);
// helpers
int		ft_putstr(char *str);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_base(unsigned long n, int is_uppercase);
int		get_num_len_base(unsigned long num, int base);

#endif
