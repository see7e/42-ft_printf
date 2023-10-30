/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:42:42 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:18:59 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list args, int count)
{
	int	num;
	int	is_negative;

	num = va_arg(args, int);
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	if (is_negative)
	{
		write(1, "-", 1);
		return (count++);
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (count++);
	}
	else
		return (count += ft_print_digits(num, NULL));
}
