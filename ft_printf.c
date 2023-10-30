/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:42:28 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:20:52 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format_specifier(const char *format, va_list args,
				int count)
{
	format++;
	if (*format == 'c')
		count += ft_print_char(args, count);
	else if (*format == 's')
		count += ft_print_string(args, count);
	else if (*format == 'p')
		count += ft_print_pointer(args, count);
	else if (*format == 'd' || *format == 'i')
		count += ft_print_decimal(args, count);
	else if (*format == 'u')
		count += ft_print_unsigned_decimal(args, count);
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hexadecimal(args, format, count);
	else if (*format == '%')
		count += ft_print_percent(count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_handle_format_specifier(format, args, count);
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
