/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:43:39 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:20:23 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list args, int count)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (count++);
	}
	else
		return (count += ft_print_digits(num, NULL));
}
