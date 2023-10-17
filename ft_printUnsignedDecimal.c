// TODO: Add header
#  include "ft_printf.h"

int	ft_printUnsignedDecimal(va_list args, int *count)
{
	unsigned int num;
	
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1); // Handle the case of num being zero
		return (*count++);
	}
	else // Call the helper function to print decimal digits
		return (*count += ft_printDigits(num, NULL));
}