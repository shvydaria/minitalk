/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 12:48:33 by dashvydk          #+#    #+#             */
/*   Updated: 2025-04-24 12:48:33 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

// %c %s %p %d%i %u %xX %
// d, s, x - exam
int	handle_specifier(char specifier, va_list args)
{
	int	chars_printed;

	chars_printed = 0;
	if (specifier == 'c')
		chars_printed = ft_printf_char(va_arg(args, int));
	else if (specifier == 'd' || specifier == 'i')
		chars_printed = ft_printf_num_s(va_arg(args, int));
	else if (specifier == 'u')
		chars_printed = ft_printf_num_u(va_arg(args, unsigned int));
	else if (specifier == 's')
		chars_printed = ft_printf_str(va_arg(args, char *));
	else if (specifier == 'p')
		chars_printed = ft_printf_pointer(va_arg(args, void *));
	else if (specifier == 'x' || specifier == 'X')
		chars_printed = ft_printf_hex(va_arg(args, unsigned int),
				specifier == 'X');
	else if (specifier == '%')
		chars_printed = ft_printf_char('%');
	else
		chars_printed = -1;
	return (chars_printed);
}

int	process_format_specifier(const char **format, va_list args)
{
	int	chars_printed;

	chars_printed = handle_specifier(**format, args);
	if (chars_printed == -1)
		return (-1);
	return (chars_printed);
}

int	write_non_format_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_chars;
	int		chars_printed;

	total_chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			chars_printed = process_format_specifier(&format, args);
		}
		else
			chars_printed = write_non_format_char(*format);
		if (chars_printed == -1)
		{
			va_end(args);
			return (-1);
		}
		total_chars += chars_printed;
		format++;
	}
	va_end(args);
	return (total_chars);
}
