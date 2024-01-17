#include "printf.h"
#include <stdio.h>

int main()
{
	int result = printf("number: %d\n", 10);
	int result1 = ft_printf("number: %d\n", 10);

	printf("original: %d\n", result);	
	printf("mine: %d\n", result1);
}