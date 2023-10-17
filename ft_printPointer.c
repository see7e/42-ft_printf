// TODO: Add header
#include "ft_printf.h"

int	ft_printPointer(va_list args, int *count)
{
	void *ptr;

	ptr = va_arg(args, void *); // Get the pointer address	
	write(1, "0x", 2); // "0x" indicate a pointer value in hexadecimal
	*count += 2;
	// Cast the pointer to an unsigned long long for printing
	ft_printDigits((unsigned long long)ptr, HEX_DIGITS_LOWER);
}