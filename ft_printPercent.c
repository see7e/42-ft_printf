// TODO: Add header
#include "ft_printf.h"

int	ft_printPercent(int *count)
{
	write(1, "%", 1); // Print '%' character
	return (*count++); // Update the character count
}