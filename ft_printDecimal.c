// TODO: Add header
#include "ft_printf.h"

int	ft_printDecimal(va_list args, int *count)
{
	int num;
	int isNegative;
	
	num = va_arg(args, int);
	isNegative = 0; // Check if the number is negative
	if (num < 0)
	{
		isNegative = 1;
		num = -num; // Make num positive for further processing
	}
	if (isNegative)
	{
		write(1, "-", 1); // Print the negative sign for negative numbers
		return (*count++);
	}
	if (num == 0)
	{
		write(1, "0", 1); // Handle the case of num being zero
		return (*count++);
	}
	else // Call the helper function to print decimal digits
		return (*count += ft_printDigits(num, NULL));
}