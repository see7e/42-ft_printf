/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:43:30 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:18:37 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(va_list args, int count)
{
	char			*str;
	unsigned int	len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	write(1, str, len);
	return (count += len);
}
