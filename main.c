#include <stdio.h>

#include "ft_printf.h"
int main()
{
	// int result = printf("%b", 55);
	// printf("%d\n", result);
	close(1);
	int	i = printf("test");
	dprintf(2, "%d\n", i);
}