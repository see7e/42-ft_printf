/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:43:25 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:18:47 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args, int count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	count += 2;
	ft_print_digits((unsigned long long)ptr, HEX_DIGITS_LOWER);
}
