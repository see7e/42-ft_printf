/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:42:55 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:11:35 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(unsigned long long n, const char hex_digits, int count)
{
	char	digit;

	if (n == 0)
		return (0);
	if (!(hex_digits == NULL))
	{
		ft_print_digits(n / 16, hex_digits);
		digit = hex_digits[n % 16];
	}
	else
	{
		ft_print_digits(n / 10, NULL);
		digit = '0' + (n % 10);
	}
	write(1, &digit, 1);
	return (count++);
}
