/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:43:04 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/30 13:17:00 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // for the veriadic arguments handling
# include "libft/libft.h" // for the other functions

// Define an array of characters for digits
# define DEC_DIGITS "0123456789"
# define HEX_DIGITS_LOWER "0123456789abcdef";
# define HEX_DIGITS_UPPER "0123456789ABCDEF";

/* Remodeled `printf` function, handles `%c`, `%s`, `%p`, `%d`, `%u`, `%x`,
* `%X`, `%%`, don´t handle any buffer for better I/O efficiency*/
int				ft_printf(const char *format, ...);

/* ************************************************************************** */
/* Is a recursive function that prints the digits of an unsigned long long int
 * `n` either in decimal or hexadecimal format. It has two main modes of
 * operation:
- Decimal Mode: If the `hex_digits` parameter is `NULL`, the function operates
  in decimal mode and prints the digits of `n` in base 10 (decimal).
- Hexadecimal Mode: If the `hex_digits` parameter is not `NULL`, the function
  operates in hexadecimal mode and prints the digits of `n` in base 16 (hex).*/
int				ft_print_digits(unsigned long long n, const char hex_digits,
					int count);

/* This function handles the format specifier passed to `ft_printf` and calls
 * the appropriate function to print the corresponding argument. It returns the
 * number of characters printed. */
static int		ft_handleFormatSpecifier(const char *format, va_list args,
					int count);

/* Handles the `%c` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_print_char(va_list args, int count);

/* Handles the `%s` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_print_string(va_list args, int count);

/* Handles the `%p` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_print_pointer(va_list args, int count);

/* Handles the `%d` and `%i` format specifiers passed to `ft_printf` and prints
 * the corresponding argument. It returns the number of characters printed. */
int				ft_print_decimal(va_list args, int count);

/* Handles the `%u` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_print_unsigned_decimal(va_list args, int count);

/* Handles the `%x` and `%X` format specifiers passed to `ft_printf` and prints
 * the corresponding argument. It returns the number of characters printed. */
int				ft_print_hexadecimal(va_list args, const char *format,
					int count);

/* Handles the `%%` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_print_percent(int count);

#endif