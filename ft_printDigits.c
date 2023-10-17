// TODO: Add Header
#include "ft_printf.h"

int	ft_printDigits(unsigned long long n, const char hexDigits, int *count)
{
	char digit; // Digit variable to store the current digit
	
	if (n == 0)
		return (0);
	if (!(hexDigits == NULL))
	{ // Handles the hexdecimal numbers
		ft_printDigits(n / 16, hexDigits);
		digit = hexDigits[n % 16];    
	}
	else
	{ // Handles the decimal numbers
		ft_printDigits(n / 10, NULL);
		digit = '0' + (n % 10);
	}
	write(1, &digit, 1);
	return (*count++);
}