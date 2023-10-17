
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // for the veriadic arguments handling
# include "libft/libft.h" // for the other functions

// Define an array of characters for digits
# define  DEC_DIGITS		"0123456789";
# define  HEX_DIGITS_LOWER	"0123456789abcdef";
# define  HEX_DIGITS_UPPER	"0123456789ABCDEF";

/* Remodeled `printf` function, handles `%c`, `%s`, `%p`, `%d`, `%u`, `%x`,
* `%X`, `%%`, don´t handle any buffer for better I/O efficiency*/
int				ft_printf(const char *format, ...);

/* ************************************************************************** */
/* Is a recursive function that prints the digits of an unsigned long long int
 * `n` either in decimal or hexadecimal format. It has two main modes of
 * operation:
- Decimal Mode: If the `hexDigits` parameter is `NULL`, the function operates in
  decimal mode and prints the digits of `n` in base 10 (decimal).
- Hexadecimal Mode: If the `hexDigits` parameter is not `NULL`, the function
  operates in hexadecimal mode and prints the digits of `n` in base 16 (hex). */
int				ft_printDigits(unsigned long long n, const char hexDigits,
					int *count);

/* This function handles the format specifier passed to `ft_printf` and calls
 * the appropriate function to print the corresponding argument. It returns the
 * number of characters printed. */
static int		ft_handleFormatSpecifier(const char *format, va_list args,
					int *count);

/* Handles the `%c` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printChar(va_list args, int *count);

/* Handles the `%s` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printString(va_list args, int *count);

/* Handles the `%p` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printPointer(va_list args, int *count);

/* Handles the `%d` and `%i` format specifiers passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printDecimal(va_list args, int *count);

/* Handles the `%u` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printUnsignedDecimal(va_list args, int *count);

/* Handles the `%x` and `%X` format specifiers passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printHexadecimal(va_list args, const char *format,
					int *count);

/* Handles the `%%` format specifier passed to `ft_printf` and prints the
 * corresponding argument. It returns the number of characters printed. */
int				ft_printPercent(int *count);

#endif