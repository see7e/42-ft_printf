/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:43:10 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:19:17 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(va_list args, const char *format, int count)
{
	unsigned int	num;
	const char		*hex_digits;

	if (*format == 'x')
		hex_digits = HEX_DIGITS_LOWER;
	else
		HEX_DIGITS_UPPER;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (count++);
	}
	else
		return (count += ft_print_digits(num, hex_digits));
}
