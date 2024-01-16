
#include <stdio.h>
#include <stdarg.h>

// num -> required argument
// ... -> ellipsis : unspecified number of arguments
void print_ints(int num, ...)
{
	// va_list holds informations needed by the following macros
	// va_start , va_arg , va_copy and va_arg are macros used with va_list
	va_list args;

	// va_start -> setting a pointer to the spot on the call stack where our variable arguments 
	//were stored when the function was called
	va_start(args, num);

	int i  = 0;
	while (i < num)
	{
		// pull off the arguments one by one in the order they were listed  
		// takes two arguments : instance of the va_list and its data type 
		//(it most be self promoted types , we cant use chars , floats or shorts) but ints ,doubles and pointers are fine
		int value = va_arg(args, int);
		printf("%d\n", value);
		i++;
	}
	// 
	va_end(args);
}

int main()
{
	print_ints(5, 4, 5, 6, 12423, -131);

	// int result = printf("");
    
    // printf("%d characters were written", result);
}

